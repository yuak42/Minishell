/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:53:41 by yuak              #+#    #+#             */
/*   Updated: 2026/05/18 18:54:09 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	remove_token(t_token **head, t_token *token)
{
	t_token	*tmp;
	t_token	*back;

	if (!head || !*head || !token)
		return ;
	tmp = *head;
	back = NULL;
	while (tmp)
	{
		if (tmp == token)
		{
			printf("<%s> will be removed\n", tmp->value);
			if (back)
				back->next = tmp->next;
			else
				*head = tmp->next;
			// free_token(tmp);
			return ;
		}
		back = tmp;
		tmp = tmp->next;
	}
}
