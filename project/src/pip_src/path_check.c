/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-20 16:22:36 by byaprak           #+#    #+#             */
/*   Updated: 2026-05-20 16:22:36 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	error_check(t_pipe plist, struct stat statbuf)
{
	int	status;

	if (errno == EACCES)
	{
		ft_printf_fd(2, "-minishell: %s: \
			Permission denied\n", plist.argv[0]);
		status = 126;
	}
	else if (errno == ENOENT)
	{
		if (ft_strchr(plist.argv[0], '/'))
			ft_printf_fd(2, "-minishell: %s: \
				No such file or directory\n", plist.argv[0]);
		else
			ft_printf_fd(2, "-minishell: %s: \
				command not found\n", plist.argv[0]);
		status = 127;
	}
	else if (S_ISDIR(statbuf.st_mode))
	{
		ft_printf_fd(2, "minishell: %s: Is a directory\n", plist.argv[0]);
		status = 126;
	}
	return (status);
}

char	*path_check(t_pipe plist, char **ev)
{
	char		*path;
	struct stat	statbuf;
	int			status;

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
