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

static char	*get_key(char *av)
{
	int		i;
	char	*variable;
	char	check;

	i = 0;
	while (av[i] != '=' && av[i])
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

static t_env	*is_variable(char *variable, t_env *node)
{
	char	*str;

	while (node)
	{
		str = get_key(node->key);
		if (!ft_strncmp(str, variable, ft_strlen(variable) + 1))
		{
			free(str);
			return (node);
		}
		node = node->next;
		free(str);
	}
	return (NULL);
}

static int	run_export(char *av, t_env *env)
{
	char	*key;
	t_env	*node;

	key = get_key(av);
	if (!key)
	{
		perror("-minishell");
		return (0);
	}
	node = is_variable(key, env);
	if (node && !ft_strchr(av, '='))
	{
		free(key);
		return (0);
	}
	if (run_export_2(av, env, key))
		return (0);
	free(key);
	return (1);
}

static int	is_valid(char *av)
{
	if (!(*av == '_' || ft_isalpha(*av)))
	{
		ft_perror("-minishell: export: `%s': not a valid identifier\n", av);
		return (0);
	}
	av++;
	while (*av != '=' && *av)
	{
		if (!(*av == '_' || ft_isalpha(*av) || ft_isdigit(*av)))
		{
			ft_perror("-minishell: export: `%s': not a valid identifier\n", av);
			return (0);
		}
		av++;
	}
	return (1);
}

int	ft_export(char **av, t_env *env, int fd)
{
	if (!av[1])
	{
		print_export(env, fd);
		return (0);
	}
	av++;
	if (!is_valid(*av))
		return (1);
	while (*av)
	{
		if (!run_export(*av, env))
			return (1);
		av++;
	}
	return (0);
}
