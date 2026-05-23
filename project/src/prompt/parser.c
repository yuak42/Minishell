/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:44:46 by yuak              #+#    #+#             */
/*   Updated: 2026/05/23 08:32:49 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static void	close_pipes(t_node *nodes);

int	parser(t_shell *shell)
{
	int	status;

	status = tokenizer(shell->line, shell);
	if (status == 2)
		return (free(shell->line), 2);
	if (status == 0)
	{
		shell->nodes = create_nodes(shell->tokens);
		if (!shell->nodes)
			return (free_tokens(shell->tokens), free(shell->line), 2);
		status = heredoc(shell);
		if (status == 1)
			return (free_parser(shell), 2);
		if (status == 2)
		{
			shell->exit_status = 128 + status;
			return (close_pipes(shell->nodes), free_parser(shell), 1);
		}
	}
	else
		return (free(shell->line), 1);
	return (0);
}

static void	close_pipes(t_node *nodes)
{
	while (nodes)
	{
		while (nodes->redir)
		{
			if (nodes->redir->type == token_heredoc)
				close(nodes->redir->read);
			nodes->redir = nodes->redir->next;
		}
		nodes = nodes->next;
	}
}
