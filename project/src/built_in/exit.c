/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-10 00:39:28 by byaprak           #+#    #+#             */
/*   Updated: 2026-05-10 00:39:28 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"prompt.h"

static int	ft_mod(int code)
{
	int c;

	c = (char)code;
	return (c);
}
int arry_isdigit(char *s)
{
	if (!ft_isdigit(*s) && *s != '+' && *s != '-' )
		return (0);
	s++;
	while(*s)
	{
		if (!ft_isdigit(*s))
		{
			return (0);
		}
		s++;
	}
	
	return (1);
}

int ft_exit_ft(char **av, t_shell *shell)
{
	int code;
 // deneme
	av++;
	printf("logout\n");
	if (!*av)
		exit(shell->exit_status);
	if (av[1])
	{
		ft_printf_fd(2, "-minishell: exit: too many arguments\n");
		return (1);
	}
	if (!arry_isdigit(*av))
	{
		ft_printf_fd(2, "-minishell: exit: %s: numeric argument required\n", *av);
		exit(2);
	}
	code = ft_atoi(av[0]);
	//printf("CODE:%d\n", code);
	if (code < 0 || code > 255)
		code = ft_mod(code);
	//free_tokens(shell->tokens);
	//free(shell->line);
	//free_ev(shell->ev);
	exit(code);
}
