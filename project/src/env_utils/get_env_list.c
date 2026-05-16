/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:54:19 by yuak              #+#    #+#             */
/*   Updated: 2026/05/16 19:00:29 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static char	*get_key(char *env);
static char	*get_value(char *env);

t_env	*get_env_list(char **env)
{
	t_env	*head;
	t_env	*ev_node;
	t_env	*last;

	head = NULL;
	while (*env)
	{
		ev_node = (t_env *) malloc(sizeof(t_env));
		if (!ev_node)
			return (free_ev(head), NULL);
		ev_node->key = get_key(*env);
		if (!ev_node->key)
			return (free(ev_node), free_ev(head), NULL);
		ev_node->value = get_value(*env);
		if (!ev_node->value)
			return (free(ev_node->key), free(ev_node), free_ev(head), NULL);
		ev_node->next = NULL;
		if (head == NULL)
		{
			head = ev_node;
			head->prev = NULL;
			last = ev_node;
		}
		else
		{
			last->next = ev_node;
			ev_node->prev = last;
			last = last->next;
		}
		env++;
	}
	return (head);
}

static char	*get_key(char *env)
{
	char	*str;
	char	*key;
	size_t	i;

	str = env;
	i = 0;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	key = (char *) malloc(sizeof(char) * (i + 1));
	if (!key)
		return (NULL);
	i = 0;
	while (str[i] != '=' && str[i] != '\0')
	{
		key[i] = str[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

static char	*get_value(char *env)
{
	char	*str;
	char	*value;
	size_t	i;

	str = env;
	i = 0;
	while (*str != '=' && *str)
		str++;
	if (*str == '\0')
	{
		value = ft_strdup("");
		if (!value)
			return (NULL);
		return (value);
	}
	str++;
	while (str[i])
		i++;
	value = (char *) malloc(sizeof(char) * (i + 1));
	if (!value)
		return (NULL);
	i = 0;
	while (str[i])
	{
		value[i] = str[i];
		i++;
	}
	value[i] = '\0';
	return (value);
}