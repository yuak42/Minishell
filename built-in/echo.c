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

static char	*is_env(char *input)
{
	char *dest;
	char *str;
	int	i;

	str = NULL;
	i = 0;
	dest = ft_strchr(input, '$');
	dest++;
	while (dest[i] != ' ')
		i++;
	str = ft_calloc(sizeof(char) , i);
	i = 0;
	while (dest[i] != ' ')
	{
		str[i] = dest[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	print_env(t_list *ev, char *env)
{
	while (ev)
	{
		if (ft_strnstr(ev->content, env, ft_strlen(env)))
		{
			write(1, (char *)ev->content, ft_strlen(ev->content));
			break;
		}
		ev = ev->next;
	}
}

void	ft_echo(char *input, t_list *ev)
{
	char *env;

	env = NULL;
	if (ft_strchr(input, '$'))
	{
		env = is_env(input);
		print_env(ev, env);
		return ;
	}
	write(1, input, ft_strlen(input));
	if (ft_strnstr(input, "-n", 2))
		return ;
	write(1, "\n", 1);
	free(env);
}

int main (int ac, char **av, char **envp)
{
	t_list	*ev;
	char *input;

	input = ft_strdup("");
	av++;
	ev = NULL;
	ev = create_env(envp);
	if ( ac == 0)
	{
		printf("error\n");
		return (0);
	}
	while(*av)
	{
		input = ft_strjoin(input, *av);
		av++;
	}
	printf("AC:%d\n-----%s--------\n", ac, input);
	ft_echo(input, ev);
	return (0);
}
