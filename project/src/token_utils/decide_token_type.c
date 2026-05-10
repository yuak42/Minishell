/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_token_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:14 by yuak              #+#    #+#             */
/*   Updated: 2026/05/10 11:53:15 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	decide_token_type(t_token *token, char *str)
{
	if (token->state != state_normal)
	{
		token->type = token_word;
		return ;
	}
	if (!ft_strncmp(str, "|", 2))
		token->type = token_pipe;
	else if (!ft_strncmp(str, ">", 2))
		token->type = token_redir_out;
	else if (!ft_strncmp(str, "<", 2))
		token->type = token_redir_in;
	else if (!ft_strncmp(str, ">>", 3))
		token->type = token_redir_app;
	else if (!ft_strncmp(str, "<<", 3))
		token->type = token_heredoc;
	else
		token->type = token_word;
}
