/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:54:16 by yuak              #+#    #+#             */
/*   Updated: 2026/05/17 15:44:16 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char	*get_env_value(t_env *ev, char *key)
{
	while (ev)
	{
		if (!ft_strncmp(ev->key, key, ft_strlen(key) + 1))
			return (ev->value);
		ev = ev->next;
	}
	return (NULL);
}
