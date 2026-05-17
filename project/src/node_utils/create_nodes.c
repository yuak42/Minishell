/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:40 by yuak              #+#    #+#             */
/*   Updated: 2026/05/17 09:59:26 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	add_arg(char ***argv, char *arg);
void	handle_op(t_token **tokens, t_node *node);
t_node	*get_node(t_token **tokens);
int	*add_int(int *arr, int num);

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
			handle_op(tokens, node); // inside of it, tokens also can be shifted
			if (!node)
				return (NULL);
		}
	}
	return (node);
}

void	handle_op(t_token **tokens, t_node *node)
{
	if (!(*tokens)->next || (*tokens)->next->type != token_word)
	{
		free_nodes(node);
		*tokens = (*tokens)->next;
		node = NULL;
		print_error("syntax error!\n");
		return ;
	}
	if ((*tokens)->type == token_redir_out)
	{
		add_arg(&node->outfile, (*tokens)->next->value); // add error checks
		node->append = add_int(node->append, 0);
	}
	else if ((*tokens)->type == token_redir_in)
	{
		add_arg(&node->infile, (*tokens)->next->value);
		node->heredoc = add_int(node->heredoc, 0);
	}
	else if ((*tokens)->type == token_redir_app)
	{
		add_arg(&node->outfile, (*tokens)->next->value);
		node->append = add_int(node->append, 1);
	}
	else if ((*tokens)->type == token_heredoc)
	{
		add_arg(&node->infile, (*tokens)->next->value);
		node->heredoc = add_int(node->heredoc, 1);
	}
	*tokens = (*tokens)->next->next;
}

int	*add_int(int *arr, int num)
{
	int	*ret;
	int	i;

	if (!arr)
	{
		ret = (int *) ft_calloc(2, sizeof(int));
		if (!ret)
			return (free(arr), NULL);
		ret[0] = num;
		ret[1] = -1;
	}
	else
	{
		i = 0;
		while (arr[i] != -1)
			i++;
		ret = (int *) ft_calloc(i + 1, sizeof(int));
		if (!ret)
			return (free(arr), NULL);
		i = 0;
		while (arr[i] != -1)
		{
			ret[i] = arr[i];
			i++;
		}
		ret[i] = num;
		ret[i + 1] = -1;
	}
	free(arr);
	return (ret);
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
	new_argv = (char **) malloc(sizeof(char *)*(len + 2));
	if (!new_argv)
	{
		free(*argv);
		*argv = NULL; //perror later maybe
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
