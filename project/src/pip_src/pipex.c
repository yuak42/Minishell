/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:23:32 by byaprak           #+#    #+#             */
/*   Updated: 2025/09/28 20:09:05 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child(t_pipe plist)
{
	int		status;

	set_child_signals();
	if (!ft_fdswap(plist.inp, 0) || !ft_fdswap(plist.out, 1))
	{
		ft_all_free(plist);
		exit(1);
	}
	if (plist.inp != 0)
		close(plist.inp);
	if (plist.out != 1)
		close(plist.out);
	if (is_builtin(plist.argv))
	{
		status = run_builtin(plist.argv, plist.shell, 1);
		ft_all_free(plist);
		exit(status);
	}
	ft_run_process(plist);
}

int	ft_process(t_pipe plist, int (*pipefd)[2], int pc, int *pd)
{
	int	pid;
	int	i;

	i = 0;
	pid = fork();
	if (pid == -1)
	{
		perror("-minishell");
		ft_all_free(plist);
	}
	if (pid == 0)
	{
		while (i < pc)
		{
			if ((pipefd[i][1] != plist.out))
				close(pipefd[i][1]);
			if ((pipefd[i][0] != plist.inp))
				close(pipefd[i][0]);
			i++;
		}
		free(pipefd);
		free(pd);
		ft_child(plist);
	}
	return (pid);
}

int	ft_pipex(t_node *node, t_shell *shell, int ac)
{
	int	(*fd)[2];
	int	*pd;
	int	i;
	int	status;

	pd = malloc(sizeof(int) * (ac));
	fd = malloc(sizeof(*fd) * (ac - 1));
	ft_pip(ac, fd);
	i = 0;
	while (i < ac)
	{
		pd[i] = ft_process(ft_struct(node, shell, fd, i), fd, ac - 1, pd);
		i++;
		node = node->next;
	}
	ft_pipeclose(fd, ac - 1);
	status = ft_wait(pd, ac);
	free(fd);
	free(pd);
	return (WEXITSTATUS(status));
}
