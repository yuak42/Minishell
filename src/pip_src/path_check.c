/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:22:36 by byaprak           #+#    #+#             */
/*   Updated: 2026/05/23 14:01:27 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	error_check(t_pipe plist, struct stat statbuf)
{
	int		status;
	char	*av;

	status = 0;
	av = plist.argv[0];
	if (errno == EACCES)
	{
		ft_printf_fd(2, "-minishell: %s: Permission denied\n", av);
		status = 126;
	}
	else if (errno == ENOENT)
	{
		if (ft_strchr(av, '/'))
			ft_printf_fd(2, "-minishell: %s: No such file or directory\n", av);
		else
			ft_printf_fd(2, "-minishell: %s: command not found\n", av);
		status = 127;
	}
	else if (S_ISDIR(statbuf.st_mode))
	{
		ft_printf_fd(2, "minishell: %s: Is a directory\n", av);
		status = 126;
	}
	return (status);
}

char	*path_check(t_pipe plist, char **ev)
{
	char		*path;
	struct stat	statbuf;
	int			status;

	status = 0;
	path = ft_path(plist.argv, ev, &statbuf, &status);
	if (!path)
	{
		status = error_check(plist, statbuf);
		ft_all_free(plist);
		free_str(ev, -1);
		exit(status);
	}
	return (path);
}
