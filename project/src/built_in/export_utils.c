/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-20 17:49:36 by byaprak           #+#    #+#             */
/*   Updated: 2026-05-20 17:49:36 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	print_export(t_env *env, int fd)
{
	while (env)
	{
		if (!env->value[0])
		{
			if (ft_printf_fd(fd, "declare -x %s\n", env->key) < 0)
			{
				perror("");
		
			}
		}
		else if (ft_printf_fd(fd, "declare -x %s=\"%s\"\n",
				env->key, env->value) < 0)
		{
			perror("");
		}
		env = env->next;
	}
}

int	run_export_2(char *av, t_env *env, char *key)
{
	char	*value;

	value = ft_strdup(ft_strchr(av, '=') + 1);
	if (ft_strchr(av, '='))
	{
		if (!value)
		{
			perror("-minishell");
			return (1);
		}
		if (set_env_value(env, key, value))
			return (1);
	}
	else if (*av)
	{
		if (set_env_value(env, key, value))
			return (1);
	}
	return (0);
}
