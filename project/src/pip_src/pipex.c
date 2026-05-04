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

void	ft_child(char **argv, t_env *envp, int std_int, int std_out)
{
	char	*path;
	char	**ev;
	// cmd = ft_split(argv, ' ');
	// if (!cmd)
	// 	path = NULL;
	//else
	ev = env_to_arry(envp);
	path = ft_path(argv[0], ev, argv);
	if (!path)
	{
		perror("-minishell:");
		free_str(ev, -1);
		ft_free(argv);
		exit(127);
	}
	free_str(ev, -1);
	if (!ft_fdswap(std_int, 0) || !ft_fdswap(std_out, 1))
	{
		ft_exit(path, argv);
	}
	close(std_int);
	close(std_out);
	
	ft_run_process(path, argv, envp);
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

int	ft_pipex(t_node *node, t_env *ev, int ac)
{
	int	(*fd)[2];
	int	*pd;
	int	i;
	int	status;

	pd = malloc(sizeof(int) * (ac));
	fd = malloc(sizeof(*fd) * (ac - 1));
	ft_pip(ac, fd);
	//pd[0] = ft_process(ft_struct(node, ev, fd, 0), fd, ac - 1, pd);
	i = 0;
	while (i < ac)
	{
		pd[i] = ft_process(ft_struct(node, ev, fd, i), fd, ac - 1, pd);
		i++;
	}
	// if (ac != 1)
	// 	pd[ac - 1] = ft_process(ft_struct(node, ev, fd, ac - 2), fd, ac - 1, pd);
	ft_pipeclose(fd, ac - 1);
	status = ft_wait(pd, ac - 1);
	free(fd);
	free(pd);
	exit (WEXITSTATUS(status));
}
