/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 09:53:55 by yuak              #+#    #+#             */
/*   Updated: 2026/05/21 21:07:25 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	get_input(int *p, t_redir *redir, t_shell *shell);
static char	*deal_line(char *line, t_shell *shell, t_redir *redir);
static int	get_child(t_redir *redir, t_shell *shell);

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
				if (get_child(redir, shell))
					return (1);
			}
			redir = redir->next;
		}
		head = head->next;
	}
	return (0);
}

static int	get_child(t_redir *redir, t_shell *shell)
{
	int	p[2];
	int	pid;
	int	status;

	if (pipe(p) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
	{
		perror("-minishell");
		return (close(p[1]), close(p[0]), 1);
	}
	if (pid == 0)
	{
		if (get_input(p, redir, shell))
			return (1);
	}
	status = ft_wait(&pid, 1);
	shell->exit_status = status + g_signal;
	close(p[1]);
	redir->read = p[0];
	if (WIFSIGNALED(status))
		return (0);
	else if (WIFEXITED(status))
		return (0);
	return (1);
}

static int	get_input(int *p, t_redir *redir, t_shell *shell)
{
	char	*line;
	char	*str;

	set_heredoc_signals();
	while (1)
	{
		line = readline("> ");
		if (g_signal == SIGINT)
		{
			free(line);
			close(p[0]);
			close(p[1]);
			exit(130);
		}
		if (!line)
			no_eof_delimeter(p, redir);
		if (is_delimeter(line, redir->file))
			break ;
		str = deal_line(line, shell, redir);
		if (!str)
		{
			free(line);
			close(p[1]);
			close(p[0]);
			exit(1);
		}
		write_for_heredoc(p, str);
		free(str);
	}
	free(line);
	close(p[0]);
	close(p[1]);
	exit(0);
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
