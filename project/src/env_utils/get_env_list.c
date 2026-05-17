/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:54:19 by yuak              #+#    #+#             */
/*   Updated: 2026/05/17 15:44:33 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static char	*get_key(char *env);
static char	*get_value(char *env);
static char	*get_empty_value(void);

t_env	*get_env_list(char **env)
{
	t_env	*head;
	t_env	*ev_node;

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
		add_env_to_last(&head, ev_node);
		env++;
	}
	return (head);
}

static char	*get_key(char *env)
{
	char	*key;
	size_t	i;

	i = 0;
	while (env[i] != '=' && env[i] != '\0')
		i++;
	key = (char *) malloc(sizeof(char) * (i + 1));
	if (!key)
		return (perror("Error"), NULL);
	i = 0;
	while (env[i] != '=' && env[i] != '\0')
	{
		key[i] = env[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

static char	*get_value(char *env)
{
	char	*value;
	size_t	i;

	i = 0;
	while (*env && *env != '=')
		env++;
	if (*env == '\0')
		return (get_empty_value());
	env++;
	while (env[i])
		i++;
	value = (char *) malloc(sizeof(char) * (i + 1));
	if (!value)
		return (perror("Error"), NULL);
	i = 0;
	while (env[i])
	{
		value[i] = env[i];
		i++;
	}
	value[i] = '\0';
	return (value);
}

static char	*get_empty_value(void)
{
	char	*value;

	value = ft_strdup("");
	if (!value)
		return (print_error("Error: ft_strdup\n"), NULL);
	return (value);
}
