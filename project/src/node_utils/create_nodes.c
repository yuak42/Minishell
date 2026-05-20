/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:40 by yuak              #+#    #+#             */
/*   Updated: 2026/05/20 18:17:33 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

t_node	*get_node(t_token **tokens);

t_node	*create_nodes(t_token *tokens)
{
	t_node	*head;
	t_node	*node;

	head = NULL;
	while (tokens)
	{
		if (tokens->type == token_pipe)
			node->pipe_out = 1;
		node = get_node(&tokens);
		if (!node)
			return (free_nodes(head), NULL);
		add_last_node(&head, node);
	}
	return (head);
}

t_node	*init_node(t_token **tokens);

t_node	*get_node(t_token **tokens)
{
	t_node	*node;

	node = init_node(tokens);
	if (!node)
		return (NULL);
	while (*tokens && (*tokens)->type != token_pipe)
	{
		if ((*tokens)->type == token_word)
		{
			add_arg(&node->argv, (*tokens)->value);
			if (!node->argv)
				return (free_nodes(node), NULL);
			*tokens = (*tokens)->next;
		}
		else
		{
			handle_op(tokens, node);
			if (!node)
				return (NULL);
		}
	}
	return (node);
}

t_node	*init_node(t_token **tokens)
{
	t_node	*node;

	node = (t_node *) ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	if ((*tokens)->type == token_pipe)
	{
		node->pipe_in = 1;
		*tokens = (*tokens)->next;
	}
	return (node);
}
