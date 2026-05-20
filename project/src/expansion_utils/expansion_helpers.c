/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:10:58 by yuak              #+#    #+#             */
/*   Updated: 2026/05/20 16:21:46 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

char	*connect_str(char *before, char *to_add)
{
	char	*final;

	if (!to_add || !before)
		(free(before), free(to_add), return (NULL))
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
	res = connect_exp(res, key, shell);
	if (!res)
		return (free(key), free(res), NULL);
	free(key);
	return (res);
}

char	*connect_exp(char *res, char *key, t_shell *shell)
{
	char	*value;

	if (!ft_strncmp("?", key, 1))
	{
		value = ft_itoa(shell->exit_status);
		if (!value)
			return (NULL);
		res = connect_str(res, value);
		return (res);
	}
	value = get_env_value(shell->ev, key);
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
