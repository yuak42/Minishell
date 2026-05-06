/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-01 23:16:11 by byaprak           #+#    #+#             */
/*   Updated: 2026-05-01 23:16:11 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"prompt.h"

int	is_builtin(char **argv)
{
	if (ft_strnstr(argv[0], "cd", 2) && ft_strlen(argv[0]) == 2)
		return (1);
	else if (ft_strnstr(argv[0], "echo", 4) && ft_strlen(argv[0]) == 4)
		return (1);
	else if (ft_strnstr(argv[0], "env", 3) && ft_strlen(argv[0]) == 3)
		return (1);
	else if (ft_strnstr(argv[0], "export", 6) && ft_strlen(argv[0]) == 6)
		return (1);
	else if (ft_strnstr(argv[0], "pwd", 3) && ft_strlen(argv[0]) == 3)
		return (1);
	else if (ft_strnstr(argv[0], "unset", 5) && ft_strlen(argv[0]) == 5)
		return (1);
	else
		return (0);
}

int	run_builtin(char **argv, t_env **ev, int fd)
{
	if (ft_strnstr(argv[0], "cd", 2) && ft_strlen(argv[0]) == 2)
		return (ft_cd(argv, *ev));
	else if (ft_strnstr(argv[0], "echo", 4) && ft_strlen(argv[0]) == 4)
		return (ft_echo(argv, *ev, fd));
	else if (ft_strnstr(argv[0], "env", 3) && ft_strlen(argv[0]) == 3)
		return (ft_env(*ev, fd));
	else if (ft_strnstr(argv[0], "export", 6) && ft_strlen(argv[0]) == 6)
		return (ft_export(argv, *ev, fd));
	else if (ft_strnstr(argv[0], "pwd", 3) && ft_strlen(argv[0]) == 3)
		return (ft_pwd());
	else if (ft_strnstr(argv[0], "unset", 5) && ft_strlen(argv[0]) == 5)
		return (ft_unset(argv, ev));
	else
		return (-1);
}

int	nodes_len(t_node *nodes)
{
	int i = 0;

	while (nodes)
	{
		i++;
		nodes = nodes->next;
	}
	return (i);
}
