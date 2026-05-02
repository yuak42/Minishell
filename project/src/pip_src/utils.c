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
		perror("");
		return (0);
	}
	if (dup2(std_new, std_old) == -1)
	{
		perror("");
		return (0);
	}
	return (1);
}

void	ft_run_process(char *path, char **argv, char **envp)
{
	if (execve(path, argv, envp) == -1)
	{
		free(path);
		ft_free(argv);
		exit(EXIT_FAILURE);
	}
}

t_pipe	ft_struct(char *argv, char **envp, int inp, int out)
{
	t_pipe	p_list;

	p_list.argv = argv;
	p_list.envp = envp;
	p_list.inp = inp;
	p_list.out = out;
	return (p_list);
}
