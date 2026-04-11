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

static void	print_env(t_env *ev, char *av)
{
	av++;
	while (ev)
	{
		if (!ft_strncmp(av, ev->key, ft_strlen(av) + 1))
		{
			write(1, ev->value, ft_strlen(ev->value)); // maybe error check here too
			break ;
		}
		ev = ev->next;
	}
	(void) av;
}

static int	echo_print(char *av, t_env *ev)
{
	//char	*n_check;

	//n_check = av[1];
	while (*av)
	{
		if (*av == '$')
		{
			av++;
			print_env(ev, av);
			return (1);
		}
		if (!ft_putchar_fd(*av, 1))
			return (0);
		av++;
	}
	return (1);
	(void) ev;
	// if (ft_strnstr(n_check, "-n", 2))
	// 	return ;
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

static int	run_echo(char **av, t_env *ev)
{
	int	new_line; 

	new_line = is_print(*av);
	while (!is_print(*av))
		av++;
	while (*av)
	{
		// if (!echo_print(*av, ev))
		// 	return (0);
		echo_print(*av, ev);
		if (!ft_putchar_fd(' ', 1))
			return (0);
		if (*(av + 1))
		{

			if (!ft_putchar_fd(' ', 1))
				return (0);
		}
		av++;
	}
	if (new_line)
	{
		if (!ft_putchar_fd('\n', 1))
			return (0);
	}
	return (1);
}

int	ft_echo(char **av, t_env *ev)
{
	if (!av[1])
	{
		if (!ft_putchar_fd('\n', 1))
			return (1);
		return (0);
	}
	av++;
	if (!run_echo(av, ev))
		return (1);
	return (0);
}

// echo $0 incele
