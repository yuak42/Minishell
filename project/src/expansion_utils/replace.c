/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:51 by yuak              #+#    #+#             */
/*   Updated: 2026/05/10 12:09:04 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static void	replace_value(char **str, size_t var_len, char *value, size_t len);
static void	fill(char **str, size_t var_len, char *value, char *new_value);

void	replace(char **str, char *var_name, t_env *ev)
{
	size_t	len;
	size_t	var_len;

	var_len = ft_strlen(var_name);
	while (ev)
	{
		if (!(ft_strncmp(var_name, ev->key, var_len + 1)))
		{
			len = ft_strlen(*str) - var_len + ft_strlen(ev->value);
			replace_value(str, var_len, ev->value, len);
			return ;
		}
		ev = ev->next;
	}
	change_to_none(str, var_name);
}

static void	replace_value(char **str, size_t var_len, char *value, size_t len)
{
	char	*new_value;

	new_value = (char *) ft_calloc(len, sizeof(char));
	if (!new_value)
	{
		free(*str);
		*str = NULL;
		return ;
	}
	fill(str, var_len, value, new_value);
	free(*str);
	*str = new_value;
}

static void	fill(char **str, size_t var_len, char *value, char *new_value)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((*str)[i] != '$')
	{
		new_value[i] = (*str)[i];
		i++;
	}
	j = i;
	while (value[i])
	{
		new_value[i] = value[i];
		i++;
	}
	j += var_len + 1;
	while ((*str)[j])
	{
		new_value[i] = (*str)[j];
		j++;
		i++;
	}
}
