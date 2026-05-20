/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-23 22:13:56 by byaprak           #+#    #+#             */
/*   Updated: 2026-03-23 22:13:56 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	echo_print(char *av, t_env *ev, int fd)
{
	int	i;

	i = 0;
	while (i < 100000)
		i++;
	while (*av)
	{
		if (!ft_putchar_fd(*av, fd))
			return (0);
		av++;
	}
	return (1);
	(void) ev;
}

static int	is_print(char *str)
{
	if (!str)
		return (1);
	if (*str != '-')
		return (1);
	str++;
	if (!(*str))
		return (1);
	while (*str)
	{
		if (*str != 'n')
			return (1);
		str++;
	}
	return (0);
}

static int	run_echo(char **av, t_env *ev, int fd)
{
	int	new_line;

	new_line = is_print(*av);
	while (!is_print(*av))
		av++;
	while (*av)
	{
		if (!echo_print(*av, ev, fd))
			return (0);
		if (*(av + 1))
		{
			if (!ft_putchar_fd(' ', fd))
				return (0);
		}
		av++;
	}
	if (new_line)
	{
		if (!ft_putchar_fd('\n', fd))
			return (0);
	}
	return (1);
}

int	ft_echo(char **av, t_env *ev, int fd)
{
	if (!av[1])
	{
		if (!ft_putchar_fd('\n', fd))
			return (1);
		return (0);
	}
	av++;
	if (!run_echo(av, ev, fd))
		return (1);
	return (0);
}
