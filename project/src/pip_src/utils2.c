/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 14:55:48 by byaprak           #+#    #+#             */
/*   Updated: 2025/09/28 20:09:14 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipeclose(int (*pipefd)[2], int pc)
{
	int	i;

	i = 0;
	while (i < pc)
	{
		close(pipefd[i][0]);
		close(pipefd[i][1]);
		i++;
	}
}

int	ft_af(char *s)
{
	int	fd;

	fd = open(s, O_WRONLY | O_CREAT | O_APPEND, 0777);
	return (fd);
}

int	ft_wait(int *array, int count)
{
	int	i;
	int	status;

	i = 0;
	while (i < count)
	{
		if (waitpid(array[i], &status, 0) == -1)
			perror("");
		i++;
	}
	return (status);
}

void	ft_pip(int ac, int (*fd)[2])
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		if (pipe(fd[i]) == -1)
		{
			perror("minishell");
			return ;
		}
		i++;
	}
}
