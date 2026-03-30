/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-23 22:13:56 by byaprak           #+#    #+#             */
/*   Updated: 2026-03-23 22:13:56 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	print_env(t_list *ev, char *av)
{
	char	*str;
	//int i = 1;
	//printf("----------------------------%s---------------\n", av);
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

static void	str_print(char **av)
{
	(*av)++;
	while (*av)
	{
	if (ft_strchr(*av, 39))
	{
		(*av)[ft_strlen(*av) - 1] = '\0';
		//printf("DEBUG:%s\n------%d-------\n", *av, ft_strlen(*av));
	}
		write(1, *av, ft_strlen(*av));
		av++;
		write(1, " ", 1);
	}
}

static void	echo_print(char *av, t_list *ev)
{
	//char	*n_check;

	//n_check = av[1];
	while (*av)
	{
		if (*av == '$')
		{
			print_env(ev, av);
			av++;
			return ;
		}
		write(1, av, 1);
		av++;
	}
	// if (ft_strnstr(n_check, "-n", 2))
	// 	return ;
}
static int	is_print(char *str)
{
	if (*str != '-')
		return (1);
	str++;
	while (*str)
	{
		if (*str != 'n')
			return (1);
		str++;
	}
	return (0);
}

static void	run_echo(char **av, t_list *ev)
{
	int	new_line;

	new_line = is_print(*av);
	if (av[0][0] == 39)
	{
		str_print(av);
		write(1, "\n", 1);
		return ;
	}
	while (!is_print(*av))
		av++;
	while (*av)
	{
		echo_print(*av, ev);
		write(1, " ", 1);
		av++;
	}
	if (new_line)
		write(1, "\n", 1);
}

void	ft_echo(char **av, t_list *ev)
{
	if (!av[1])
	{
		write(1, "\n", 1);
		return ;
	}
	av++;
	run_echo(av, ev);
}
