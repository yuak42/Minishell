/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:22 by yuak              #+#    #+#             */
/*   Updated: 2026/05/10 11:53:23 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	is_syntax_correct(t_token *tokens);
static t_token	*tokenizer(char *line, t_shell *shell);

void	basic_prompt(t_shell *shell)
{
	char	*line;
	t_token	*tokens;
	t_node	*nodes;

	while (1)
	{
		line = readline("$ ");
		if (!line)
			break ;
		if (*line && !is_only_spaces(line))
			add_history(line);
		tokens = tokenizer(line, shell);
		if (tokens)
		{
			nodes = create_nodes(tokens);
			if (nodes)
			{
				//print_nodes(nodes);
				execute(nodes, shell);
				free_nodes(nodes);
			}
		}
		free_tokens(tokens);
		free(line); // always free at the end of loop
	}
	rl_clear_history();
}

static t_token	*tokenizer(char *line, t_shell *shell)
{
	t_token	*tokens;

	tokens = generate_tokens(line);
	if (!tokens)
	{
		shell->exit_status = 1;
		return (NULL);
	}
	if (expansion(tokens, shell))
	{
		free_tokens(tokens);
		shell->exit_status = 1;
		return (NULL);
	}
	if (!is_syntax_correct(tokens))
	{
		printf("syntax error!\n"); // print error maybe
		shell->exit_status = 1;
		return (NULL);
	}
	return (tokens);
}

static int	is_syntax_correct(t_token *tokens)
{
	if (tokens->type == token_pipe)
		return (0);
	while (tokens)
	{
		if (tokens->type != token_word && tokens->type != token_pipe)
		{
			if (!tokens->next || tokens->next->type != token_word)
				return (0);
			tokens = tokens->next;
		}
		if (tokens->type == token_pipe)
		{
			if (!tokens->next || tokens->next->type == token_pipe)
				return (0);
		}
		tokens = tokens->next;
	}
	return (1);
}