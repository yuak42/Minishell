/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:00 by yuak              #+#    #+#             */
/*   Updated: 2026/05/10 12:05:07 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	print_tokens(t_token	*tokens)
{
	while (tokens)
	{
		if (tokens->type == token_word)
		{
			if (tokens->state == state_normal)
				printf("[WORD: %s, NORMAL] ", tokens->value);
			else if (tokens->state == state_quote_single)
				printf("[WORD: %s, SINGLE_QUOTE] ", tokens->value);
			else
				printf("[WORD: %s, DOUBLE_QUOTE] ", tokens->value);
		}
		else if (tokens->type == token_pipe)
			printf("[PIPE: %s] ", tokens->value);
		else if (tokens->type == token_redir_in)
			printf("[REDIR_IN: %s] ", tokens->value);
		else if (tokens->type == token_redir_out)
			printf("[REDIR_OUT: %s] ", tokens->value);
		else if (tokens->type == token_redir_app)
			printf("[REDIR_APP: %s] ", tokens->value);
		else if (tokens->type == token_heredoc)
			printf("[REDIR_HEREDOC: %s] ", tokens->value);
		tokens = tokens->next;
	}
	printf("\n");
}
