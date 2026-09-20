/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:37 by yuak              #+#    #+#             */
/*   Updated: 2026/05/23 10:03:21 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static void	free_redir(t_redir *redir);

void	free_nodes(t_node *nodes)
{
	t_node	*temp;

	while (nodes)
	{
		temp = nodes;
		free(nodes->argv);
		free_redir(nodes->redir);
		nodes = nodes->next;
		free(temp);
	}
}

static void	free_redir(t_redir *redir)
{
	t_redir	*temp;

	temp = redir;
	while (temp)
	{
		redir = redir->next;
		free(temp);
		temp = redir;
	}
}
