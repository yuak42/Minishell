/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:54:13 by yuak              #+#    #+#             */
/*   Updated: 2026/05/15 12:54:21 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	set_env_value(t_env *ev, char *key, char *value)
{
	t_env	*head;
	t_env	*new_node;

	head = ev;
	while (ev)
	{
		if (!ft_strncmp(ev->key, key, ft_strlen(key) + 1))
		{
			free(ev->value);
			ev->value = value;
			return ;
		}
		ev = ev->next;
	}
	while (head->next)
		head = head->next;
	new_node = (t_env *) malloc(sizeof(t_env));
	if (!new_node)
		return ; // burada hata donecez sonra
	new_node->key = ft_strjoin("", key);
	new_node->value = value;
	new_node->next = NULL;
	head->next = new_node;
	new_node->prev = head;
}