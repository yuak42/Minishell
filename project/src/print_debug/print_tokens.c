/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:00 by yuak              #+#    #+#             */
/*   Updated: 2026/05/16 13:03:04 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	print_tokens(t_token	*tokens)
{
	while (tokens)
	{
		if (tokens->type == token_word)
			printf("[WORD: <%s>] ", tokens->value);
		else if (tokens->type == token_pipe)
			printf("[PIPE] ");
		else if (tokens->type == token_redir_in)
			printf("[REDIR_IN] ");
		else if (tokens->type == token_redir_out)
			printf("[REDIR_OUT] ");
		else if (tokens->type == token_redir_app)
			printf("[REDIR_APP] ");
		else if (tokens->type == token_heredoc)
			printf("[REDIR_HEREDOC] ");
		tokens = tokens->next;
	}
	printf("\n");
}
