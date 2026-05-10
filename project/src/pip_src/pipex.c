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
	char	*path;
	char	**ev;

	ev = env_to_arry(*plist.envp);
	path = ft_path(plist.argv, ev);
	if (!path)
	{
		perror("-minishell:");
		free_str(ev, -1);
		ft_free(plist.argv);
		exit(127);
	}
	free_str(ev, -1);
	if (!ft_fdswap(plist.inp, 0) || !ft_fdswap(plist.out, 1))
	{
		ft_exit(path, plist.argv);
	}
	if (plist.inp != 0)
		close(plist.inp);
	if (plist.out != 1)
		close(plist.out);
	
	ft_run_process(path, plist);
}

int	ft_process(t_pipe plist, int (*pipefd)[2], int pc, int *pd)
{
	int	pid;
	int	i;

	i = 0;
	pid = fork();
	if (pid == -1)
		perror("");
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
	status = ft_wait(pd, ac - 1);
	free(fd);
	free(pd);
	return (WEXITSTATUS(status));
}
