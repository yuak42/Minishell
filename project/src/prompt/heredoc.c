/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 09:53:55 by yuak              #+#    #+#             */
/*   Updated: 2026/05/21 10:16:41 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	get_input(t_redir *redir, t_shell *shell);
static char	*deal_line(char *line, t_shell *shell, t_redir *redir);

int	heredoc(t_shell *shell)
{
	t_node	*head;
	t_redir	*redir;

	set_heredoc_signals();
	head = shell->nodes;
	while (head)
	{
		redir = head->redir;
		while (redir)
		{
			if (redir->type == token_heredoc)
			{
				if (get_input(redir, shell))
					return (1);
			}
			redir = redir->next;
		}
		head = head->next;
	}
	return (0);
}

static int	get_input(t_redir *redir, t_shell *shell)
{
	int		p[2];
	char	*line;
	char	*str;

	if (pipe(p) == -1)
		return (1);
	while (1)
	{
		line = readline("> ");
		if (g_signal == 2 || !line)
			return (no_eof_delimeter(p, redir), 0);
		printf("here\n");
		if (is_delimeter(line, redir->file))
			break ;
		str = deal_line(line, shell, redir);
		if (!str)
			return (free(line), 1);
		write_for_heredoc(p, str);
		free(str);
	}
	free(line);
	close(p[1]);
	redir->read = p[0];
	return (0);
}

static char	*deal_line(char *line, t_shell *shell, t_redir *redir)
{
	char	*str;

	if (!redir->heredoc_exp)
	{
		str = get_expanded(line, shell);
		if (!str)
			return (NULL);
		return (free(line), str);
	}
	return (line);
}
