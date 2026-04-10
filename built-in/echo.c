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

static void	print_env(t_list *ev, char *av)
{
	char	*str;

	av++;
	while (ev)
	{
		if (ft_strnstr(ev->content, av, ft_strlen(av)))
		{
			str = ft_strchr(ev->content, '=');
			str++;
			write(1, str, ft_strlen(str));
			return ;
		}
		ev = ev->next;
	}

}

static int	echo_print(char *av, t_list *ev)
{
	//char	*n_check;

	//n_check = av[1];
	while (*av)
	{
		if (*av == '$')
		{
			print_env(ev, av);
			av++;
			return (1);
		}
		if (!ft_putchar_fd(*av, 1))
			return (0);
		av++;
	}
	return (1);
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

static int	run_echo(char **av, t_list *ev)
{
	int	new_line;

	new_line = is_print(*av);
	while (!is_print(*av))
		av++;
	while (*av)
	{
		if (!echo_print(*av, ev))
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

int	ft_echo(char **av, t_list *ev)
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
