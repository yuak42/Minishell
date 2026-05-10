/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_last_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:43 by yuak              #+#    #+#             */
/*   Updated: 2026/05/10 11:53:44 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	add_last_node(t_node **head, t_node *node)
{
	t_node *tmp;

	if (!*head)
	{
		*head = node;
		return ;
	}
	tmp = *head;	
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}