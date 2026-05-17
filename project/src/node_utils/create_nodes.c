/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:40 by yuak              #+#    #+#             */
/*   Updated: 2026/05/17 14:05:21 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	add_arg(char ***argv, char *arg);
void	handle_op(t_token **tokens, t_node *node);
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

t_node	*get_node(t_token **tokens)
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
	while (*tokens && (*tokens)->type != token_pipe)
	{
		if ((*tokens)->type == token_word)
		{
			add_arg(&node->argv, (*tokens)->value);
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

void	handle_op(t_token **tokens, t_node *node)
{
	t_redir	*redir;
	t_redir	*node_redir;

	if (!(*tokens)->next || (*tokens)->next->type != token_word)
	{
		free_nodes(node);
		node = NULL;
		print_error("syntax error!\n");
		return ;
	}
	redir = (t_redir *) ft_calloc(1, sizeof(t_redir));
	if (!redir)
	{
		free_nodes(node);
		node = NULL;
		print_error("Error! ft_calloc\n");
		return ;
	}
	redir->type = (*tokens)->type;
	redir->file = (*tokens)->next->value;
	redir->next = NULL;
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

void	add_arg(char ***argv, char *arg)
{
	char	**temp;
	size_t	len;
	char	**new_argv;

	temp = *argv;
	len = 0;
	while (temp != NULL && *temp)
	{
		len++;
		temp++;
	}
	new_argv = (char **) malloc(sizeof(char *) * (len + 2));
	if (!new_argv)
	{
		free(*argv);
		*argv = NULL;
		return ;
	}
	temp = *argv;
	len = 0;
	while (temp != NULL && *temp)
	{
		new_argv[len] = *temp;
		len++;
		temp++;
	}
	new_argv[len] = arg;
	new_argv[len + 1] = NULL;
	free(*argv);
	*argv = new_argv;
}
