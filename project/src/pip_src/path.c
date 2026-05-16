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

char	*path_check(t_pipe plist, char **ev)
{
	char *path;
	struct stat statbuf;

	path = ft_path(plist.argv, ev, &statbuf);
	if (!path)
	{
		if (errno == EACCES)
		{
			ft_printf_fd(2,"-minishell: %s: Permission denied\n", plist.argv[0]);
			ft_all_free(plist);
			free_str(ev, -1);
			free(path);
			exit(126);
		}
		else if (errno == ENOENT)
		{
			if (ft_strchr(plist.argv[0], '/'))
				ft_printf_fd(2,"-minishell: %s: No such file or directory\n", plist.argv[0]);
			else
				ft_printf_fd(2,"-minishell: %s: command not found\n", plist.argv[0]);
			ft_all_free(plist);
			free_str(ev, -1);
			free(path);
			exit(127);
		}
		else if(S_ISDIR(statbuf.st_mode))
		{
			ft_printf_fd(2, "minishell: %s: Is a directory\n", plist.argv[0]);
			ft_all_free(plist);
			free_str(ev, -1);
			free(path);
			exit (126);
		}
	}
	return (path);
}

char	*ft_path(char **argv, char **envp, struct stat *statbuf)
{
	char	*path;
	char	*path_dir;

	path_dir = ft_path_search(envp);
	if (!path_dir)
	{
		perror("-minishell");
		return (NULL);
	}
	if (ft_strrchr(argv[0], '/'))
	{
		stat(argv[0], statbuf);
		if(S_ISDIR(statbuf->st_mode))
			return (NULL);//free(path_dir)
		if (access(argv[0], F_OK | X_OK) == 0)
			return (free(path_dir), ft_strdup(argv[0]));
		else
			return (free(path_dir), NULL);
	}
	path = ft_path_access(argv[0], path_dir);
	return (path);
}

char	*ft_path_access(char *command, char *path_dir)
{
	char	*ptr;
	int		i;	
	char	**split;
	char	*cmd;

	i = 0;
	cmd = ft_strjoin("/", command);
	split = ft_split(path_dir + 5, ':');
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
