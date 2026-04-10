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
	char	check;

	i = 0;
	while(av[i] != '=' && av[i])
		i++;
	check = av[i];
	if (av[i])
		av[i] = '\0';
	variable = ft_strdup(av);
	if (!variable)
		return (0);
	if (check == '=')
		av[i] = '='; 
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

static int	is_valid(char **av)
{
	while (*av)
	{
		if (!(**av == '_' || (**av >= 'a' && **av <= 'z') || (**av >= 'A' && **av <= 'Z')))
		{
			ft_perror("-minishell: export: `%s': not a valid identifier\n", *av);
			return (0);
		}
		while (**av)
		{
			if (!(**av == '_' || (**av >= 'a' && **av <= 'z') || (**av >= 'A' && **av <= 'Z') || (**av >= '0' && **av <= '9')))
			{
				ft_perror("-minishell: export: `%s': not a valid identifier\n", *av);
				return (0);
			}
			(*av)++;
		}
		av++;
	}
	return (1);
}

int	ft_export(char **av, t_list *env)
{
	if(!av[1] && ft_strlen(*av) == 6 && ft_strnstr(*av, "export", 6))
	{
		while (env)
		{
			if (printf("declare -x %s\n", (char *)env->content) < 0)
			{
				perror("");
				return(1);
			}
			env = env->next;
		}
		return (0);
	}
	av++;
	if (!is_valid(av))
		return (1);
	while (*av)
	{
		run_export(*av, env);
		av++;
	}
	return (1);
}

// export yazıldığında alfabetik sırada yazdıracak. değişken değeri "" içinde olacak.
// readonly değişken durmunu fixle.
