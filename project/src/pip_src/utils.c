/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:38:47 by byaprak           #+#    #+#             */
/*   Updated: 2025/09/28 20:09:26 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_of(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	return (fd);
}

int	ft_cf(char *s)
{
	int	fd;

	fd = open(s, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (fd);
}

int	ft_fdswap(int std_new, int std_old)
{
	if (std_new == -1)
	{
		perror("-minishell");
		return (0);
	}
	if (dup2(std_new, std_old) == -1)
	{
		perror("-minishell");
		return (0);
	}
	return (1);
}

void	ft_run_process(t_pipe plist)
{
	char	**ev;
	char	*path;

	ev = env_to_arry(*plist.envp);
	if (!ev)
		return ;
	path = path_check(plist, ev);
	if (execve(path, plist.argv, ev) == -1)
	{
		ft_all_free(plist);
		free(path);
		free_str(ev, -1);
		perror("-minishell");
		exit(EXIT_FAILURE);
	}
}

t_pipe	ft_struct(t_node *node, t_shell *shell, int (*fd)[2], int i)
{
	t_pipe	p_list;

	p_list.node = node;
	p_list.shell = shell;
	p_list.argv = node->argv;
	p_list.envp = &shell->ev;
	p_list.inp = STDIN_FILENO;
	p_list.out = STDOUT_FILENO;
	ft_redir(node);
	if (node->infile)
		p_list.inp = node->infile;
	else if (node->pipe_in)
		p_list.inp = fd[i - 1][0];
	if (node->outfile)
		p_list.out = node->outfile;
	else if (node->pipe_out)
		p_list.out = fd[i][1];
	return (p_list);
}
