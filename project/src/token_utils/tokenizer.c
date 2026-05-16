/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:49:03 by yuak              #+#    #+#             */
/*   Updated: 2026/05/16 13:18:43 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	is_syntax_correct(t_token *tokens);
static int	is_quote_syntax_correct(t_token *tokens);

t_token	*tokenizer(char *line, t_shell *shell)
{
	shell->tokens = generate_tokens(line);
	if (!shell->tokens)
	{
		shell->exit_status = 1;
		return (NULL);
	}
	if (!is_quote_syntax_correct(shell->tokens))
	{
		print_error("syntax error!\n");
		shell->exit_status = 1;
		return (NULL);
	}
	printf("-----before expansion----\n");
	print_tokens(shell->tokens);
	if (expansion(shell))
	{
		print_error("expansion failed\n");
		free_tokens(shell->tokens);
		shell->exit_status = 1;
		return (NULL);
	}
	printf("-----after expansion----\n");
	print_tokens(shell->tokens);
	if (!is_syntax_correct(shell->tokens))
	{
		print_error("syntax error!\n");
		free_tokens(shell->tokens);
		shell->exit_status = 1;
		return (NULL);
	}
	return (shell->tokens);
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

static int	is_quote_syntax_correct(t_token *tokens)
{
	size_t	i;
	int		quote;

	while (tokens)
	{
		i = 0;
		quote = 0;
		while (tokens->value[i])
		{
			quote = get_state(tokens->value[i], quote);
			if (quote)
			{
				while (quote && tokens->value[i])
				{
					i++;
					quote = get_state(tokens->value[i], quote);
				}
				if (quote)
					return (0);
			}
			i++;
		}
		tokens = tokens->next;
	}
	return (1);
}