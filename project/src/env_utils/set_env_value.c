/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:54:13 by yuak              #+#    #+#             */
/*   Updated: 2026/05/20 10:11:12 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	is_there_var(t_env *ev, char *key, char *value);

int	set_env_value(t_env *ev, char *key, char *value)
{
	t_env	*new_node;

	if (is_there_var(ev, key, value))
		return (0);
	new_node = (t_env *) malloc(sizeof(t_env));
	if (!new_node)
		return (perror("Error"), 1);
	new_node->key = ft_strdup(key);
	if (!new_node->key)
		return (free(new_node), perror("Error"), 1);
	new_node->value = value;
	new_node->next = NULL;
	while (ev->next)
		ev = ev->next;
	new_node->prev = ev;
	ev->next = new_node;
	return (0);
}

static int	is_there_var(t_env *ev, char *key, char *value)
{
	while (ev)
	{
		if (!ft_strncmp(ev->key, key, ft_strlen(key) + 1))
		{
			free(ev->value);
			ev->value = value;
			return (1);
		}
		ev = ev->next;
	}
	return (0);
}
