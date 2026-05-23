/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 09:53:55 by yuak              #+#    #+#             */
/*   Updated: 2026/05/23 10:06:19 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	get_input(t_redir *redir, t_shell *shell);

int	heredoc(t_shell *shell)
{
	t_node	*head;
	t_redir	*redir;
	int		status;

	head = shell->nodes;
	while (head)
	{
		redir = head->redir;
		while (redir)
		{
			if (redir->type == token_heredoc)
			{
				status = get_input(redir, shell);
				set_interactive_signals();
				if (status != 0)
					return (status);
			}
			redir = redir->next;
		}
		head = head->next;
	}
	return (0);
}

static void	heredoc_child(int *p, t_redir *redir, t_shell *shell);
static int	heredoc_loop(int *p, t_redir *redir, t_shell *shell);

static int	get_input(t_redir *redir, t_shell *shell)
{
	int		p[2];
	pid_t	pid;
	int		status;

	if (pipe(p) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
		heredoc_child(p, redir, shell);
	set_sigint_ignore();
	close(p[1]);
	redir->read = p[0];
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		shell->exit_status = WEXITSTATUS(status);
	return (shell->exit_status);
}

static void	heredoc_child(int *p, t_redir *redir, t_shell *shell)
{
	int	ret;

	close(p[0]);
	set_heredoc_signals();
	ret = heredoc_loop(p, redir, shell);
	close(p[1]);
	free_shell(shell);
	if (ret != 0)
		exit(ret);
	exit(0);
}

static int	heredoc_loop(int *p, t_redir *redir, t_shell *shell)
{
	char	*line;
	char	*str;

	while (1)
	{
		line = readline("> ");
		if (g_signal != 0)
		{
			close(p[1]);
			free_shell(shell);
			exit(g_signal);
		}
		if (!line)
			return (no_eof_delimeter(p, redir), 0);
		if (is_delimeter(line, redir->file))
			break ;
		str = deal_line(line, shell, redir);
		if (!str)
			return (free(line), close(p[1]), 1);
		write_for_heredoc(p, str);
		free(str);
	}
	free(line);
	return (0);
}
