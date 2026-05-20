/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:14:27 by yuak              #+#    #+#             */
/*   Updated: 2026/05/20 18:18:44 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static t_redir	*init_redir(t_token *token);

void	handle_op(t_token **tokens, t_node *node)
{
	t_redir	*redir;
	t_redir	*node_redir;

	redir = init_redir(*tokens);
	if (!redir)
	{
		free_nodes(node);
		node = NULL;
		return ;
	}
	if (!node->redir)
		node->redir = redir;
	else
	{
		node_redir = node->redir;
		while (node_redir->next)
			node_redir = node_redir->next;
		node_redir->next = redir;
	}
	*tokens = (*tokens)->next->next;
}

static t_redir	*init_redir(t_token *token)
{
	t_redir	*redir;

	redir = (t_redir *) ft_calloc(1, sizeof(t_redir));
	if (!redir)
	{
		print_error("Error! ft_calloc\n");
		return (NULL);
	}
	redir->type = token->type;
	redir->file = token->next->value;
	redir->heredoc_exp = token->next->heredoc_exp;
	redir->next = NULL;
	return (redir);
}
