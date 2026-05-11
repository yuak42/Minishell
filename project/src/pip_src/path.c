/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:38:54 by byaprak           #+#    #+#             */
/*   Updated: 2025/09/28 20:14:17 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **str)
{
	char	**swap;

	if (!str)
		return ;
	swap = str;
	while (*str)
	{	
		free(*str);
		str++;
	}
	free(swap);
}

static char	*ft_path_search(char **envp)
{
	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH=", 5))
			return (*envp);
		envp++;
	}
	return (0);
}

void	ft_exit(char *path, char **cmd)
{
	free(path);
	ft_free(cmd);
	exit(0);
}

char	*ft_path(char **argv, char **envp)
{
	char	*path;

	if (ft_strnstr(argv[0], "/", 1) || ft_strnstr(argv[0], "./", 2))
	{
		//printf("---------------------------------------------\n");
		if (access(argv[0], F_OK | X_OK) == 0)
			return (ft_strdup(argv[0]));
		else
			return (NULL);
	}
	path = ft_path_access(envp, argv[0]);
	return (path);
}

char	*ft_path_access(char **envp, char *command)
{
	char	*ptr;
	int		i;	
	char	**split;
	char	*path;
	char	*cmd;

	i = 0;
	cmd = ft_strjoin("/", command);
	path = ft_path_search(envp);
	if (!path)
	{
		free(cmd);
		perror("");
		return (NULL);
	}
	split = ft_split(path + 5, ':');
	while (split[i])
	{
		ptr = ft_strjoin(split[i], cmd);
		if (access(ptr, F_OK | X_OK) == 0)
			return (free(cmd), ft_free(split), ptr);
		free(ptr);
		i++;
	}
	return (free(cmd), ft_free(split), NULL);
}
