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

void	ft_child(char *argv, char **envp, int std_int, int std_out)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		path = NULL;
	else
		path = ft_path(argv, envp, cmd);
	if (!path)
	{
		perror("");
		ft_free(cmd);
		exit(127);
	}
	if (!ft_fdswap(std_int, 0) || !ft_fdswap(std_out, 1))
	{
		ft_exit(path, cmd);
	}
	close(std_int);
	close(std_out);
	ft_run_process(path, cmd, envp);
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
		ft_child(plist.argv, plist.envp, plist.inp, plist.out);
	}
	return (pid);
}

int	ft_pipex(char **av, char **ev, int ac)
{
	int	(*fd)[2];
	int	*pd;
	int	i;
	int	status;

	pd = malloc(sizeof(int) * (ac - 3));
	fd = malloc(sizeof(*fd) * (ac - 4));
	ft_pip(ac, fd);
	pd[0] = ft_process(ft_struct(av[2], ev, ft_of(av[1]), fd[0][1]),
			fd, ac - 4, pd);
	i = 1;
	while (i < ac - 4)
	{
		pd[i] = ft_process(ft_struct(av[i + 2], ev, fd[i - 1][0], fd[i][1]),
				fd, ac - 4, pd);
		i++;
	}
	pd[ac - 4] = ft_process(ft_struct(av[ac - 2], ev, fd[ac - 5][0],
				ft_cf(av[ac - 1])), fd, ac - 4, pd);
	ft_pipeclose(fd, ac - 4);
	status = ft_wait(pd, ac - 3);
	free(fd);
	free(pd);
	exit (WEXITSTATUS(status));
}
