/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-01 21:34:09 by byaprak           #+#    #+#             */
/*   Updated: 2026-04-01 21:34:09 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static t_env	*is_target(t_env *env, char *av)
{
	while (env)
	{
		if (!ft_strncmp(env->key, av, ft_strlen(av) + 1))
		{
			return (env);
		}
		env = env->next;
	}
	return (NULL);
}

static void	delete_node(t_env *node)
{
	if (node->prev)
		node->prev->next = node->next;
	else
		node->next->prev = NULL;
	if (node->next)
		node->next->prev = node->prev;
	else
		node->prev->next = NULL;
	free_env_node(node);
}

int	ft_unset(char **av, t_env **env)
{
	t_env	*node;

	av++;
	if (!*av)
		return(0);
	while (*av)
	{
		node = is_target(*env, *av);
		if (node)
			delete_node(node);
		av++;
	}
	return (0);

}

// unset 1=gdtt gibi bir durumda hata yzdıracak mı?
// unset new durumunu kontrol et
