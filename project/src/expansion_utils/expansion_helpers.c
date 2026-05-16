/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:10:58 by yuak              #+#    #+#             */
/*   Updated: 2026/05/16 13:07:27 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

char	*connect_str(char *before, char *to_add) // think NULL cases later
{
	char	*final;

	final = ft_strjoin(before, to_add);
	free(before);
	free(to_add);
	if (!final)
		return (NULL);
	return (final);
}

char	*replace_exp(char *str, char *res, size_t start, size_t *i, t_shell *shell)
{
	char	*key;

	res = connect_str(res, ft_substr(str, start, *i - start));
	if (!res)
		return (NULL);
	key = get_key_name(str, i);
	if (!key)
		return (NULL);
	res = connect_exp(res, key, shell->ev);
	if (!res)
		return (free(key), free(res), NULL);
	free(key);
	return (res);
}

char	*connect_exp(char *res, char *key, t_env *ev)
{
	char	*value;

	value = get_env_value(ev, key);
	if (!value)
		res = connect_str(res, ft_strdup(""));
	else
	{
		value = ft_strdup(value);
		if (!value)
			return (NULL);
		res = connect_str(res, value);
	}
	return (res);
}


int	get_state(char c, int quote)
{
	if (c == '\'' && quote == 0)
		return (1);
	if (c == '\'' && quote == 1)
		return (0);
	if (c == '"' && quote == 0)
		return (2);
	if (c == '"' && quote == 2)
		return (0);
	return (quote);
}

