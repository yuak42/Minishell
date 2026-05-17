/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:37 by yuak              #+#    #+#             */
/*   Updated: 2026/05/17 13:56:29 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	free_nodes(t_node *nodes)
{
	t_node	*temp;

	while (nodes)
	{
		temp = nodes;
		free(nodes->argv);
		nodes = nodes->next;
		free(temp);
	}
}
