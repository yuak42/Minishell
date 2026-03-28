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

// static char	*is_env(char *input)
// {
// 	char *dest;
// 	char *str;
// 	int	i;

// 	str = NULL;
// 	i = 0;
// 	dest = ft_strchr(input, '$');
// 	dest++;
// 	while (dest[i] != ' ')
// 		i++;
// 	str = ft_calloc(sizeof(char) , i);
// 	i = 0;
// 	while (dest[i])
// 	{
// 		str[i] = dest[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

static void	print_env(t_list *ev, char *av)
{
	//int i = 1;
	//printf("----------------------------%s---------------\n", av);
	av++;
	while (ev)
	{
		if (ft_strnstr(ev->content, av, ft_strlen(av)))
		{
			write(1, (char *)(ft_strchr(ev->content, '=') + 1), ft_strlen(ev->content));
			return ;
		}
		ev = ev->next;
	}

}

void	str_print(char **av)
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

void	echo_print(char *av, t_list *ev)
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
int		is_print(char *str)
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
void	ft_echo (char **av, t_list *ev)
{
	int	new_line;

	new_line = is_print(*av);
	if (av[0][0] == 39)
	{
		str_print(av);
		write(1, "\n", 1);
		ft_lstclear(&ev, free);
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
	ft_lstclear(&ev, free);
	if (new_line)
		write(1, "\n", 1);
}

int main (int ac, char **av, char **envp)
{
	t_list	*ev;

	if (!av[1])
	{
		write(1, "\n", 1);
		return (0);
	}
	av++;
	ev = NULL;
	ev = create_env(envp);
	if (ac == 0)
	{
		printf("error\n");
		return (0);
	}
	
	ft_echo(av, ev);
}
