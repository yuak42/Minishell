/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 09:53:55 by yuak              #+#    #+#             */
/*   Updated: 2026/05/20 10:15:13 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	get_input(t_redir *redir, t_shell *shell);

int	heredoc(t_shell *shell)
{
	t_node	*head;
	t_redir	*redir;

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
		if (!line)
		{
			ft_perror("minishell: warning: here-document delimited by end-of-file (wanted `%s`)\n", redir->file);
			close(p[1]);
			redir->read = p[0];
			return (1);
		}
		if (ft_strlen(line) == ft_strlen(redir->file)
			&& ft_strncmp(line, redir->file, ft_strlen(line)) == 0)
		{
			free(line);
			break ;
		}
		if (!redir->heredoc_exp)
		{
			str = get_expanded(line, shell);
			if (!str)
				return (free(line), 1);
			free(line);
			line = str;
		}
		write(p[1], line, ft_strlen(line));
		write(p[1], "\n", 1);
		free(line);
	}
	close(p[1]);
	redir->read = p[0];
	return (0);
}
