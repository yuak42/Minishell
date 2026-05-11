/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:49:03 by yuak              #+#    #+#             */
/*   Updated: 2026/05/11 17:38:57 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	is_syntax_correct(t_token *tokens);

t_token	*tokenizer(char *line, t_shell *shell)
{
	shell->tokens = generate_tokens(line);
	if (!shell->tokens)
	{
		shell->exit_status = 1;
		return (NULL);
	}
	if (expansion(shell))
	{
		free_tokens(shell->tokens);
		shell->exit_status = 1;
		return (NULL);
	}
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
