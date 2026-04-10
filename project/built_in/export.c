/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-28 23:27:59 by byaprak           #+#    #+#             */
/*   Updated: 2026-03-28 23:27:59 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static char	*get_variable(char *av)
{
	int		i;
	char	*variable;
	int		res;

	res = 0;
	i = 0;
	while(av[i] != '=')
		i++;
	av[i] = '\0';
	res = i;
	variable = ft_strdup(av);
	if (!variable)
		return (0);
	av[res] = '='; 
	return (variable);
}

static t_list	*is_variable(char *variable, t_list *node)
{
	char	*str;

	while(node)
	{
		str = get_variable(node->content);
		if (ft_strnstr(str ,variable, ft_strlen(variable)))
		{
			free(str);
			return (node);
		}
		node = node->next;
		free(str);
	}
	return (NULL);
}

static void	run_export(char *av, t_list *env)
{
	char	*variable;
	t_list	*node;
	t_list	*new;

	variable = get_variable(av);
	if (!variable)
	{
		//free(content);
		return ;
	}
	node = is_variable(variable, env);
	if (node)
	{
		free(node->content);
		node->content = ft_strdup(av);
	}
	else
	{
		new = ft_lstnew(ft_strdup(av));
		if (new)	
			ft_lstadd_back(&env, new);
	}
	free(variable);
	}

void	ft_export(char **av, t_list *env)
{
	//printf("av[1]:%s\n", av[1]);
	if(!av[1] &&ft_strlen(*av)==6 && ft_strnstr(*av, "export", 6))
	{
		while (env)
		{
			printf("declare -x %s\n", (char *)env->content);
			env = env->next;
		}
		return ;
	}
	while (*av)
	{
		run_export(*av, env);
		av++;
	}
	return ;
}

// Yeni değişkeni hangi sırada eklediğini fixle. 