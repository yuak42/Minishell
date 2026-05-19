/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:16 by yuak              #+#    #+#             */
/*   Updated: 2026/05/19 18:30:29 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	add_token_last(t_token **tokens, t_token *token)
{
	t_token	*tmp;

	tmp = *tokens;
	if (!tmp)
		*tokens = token;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = token;
		token->prev = tmp;
	}
}
