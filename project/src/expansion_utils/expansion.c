/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:54 by yuak              #+#    #+#             */
/*   Updated: 2026/05/16 11:17:14 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	expand(char **value, t_shell *shell);
static int	get_state(char c, int quote);
static char	*connect_exp(char *res, char *key, t_env *ev);
static char	*replace_exp(char *str, char *res, size_t start, size_t i, t_shell *shell);

int	expansion(t_shell *shell)
{
	t_token	*tokens;

	tokens = shell->tokens;
	while (tokens)
	{
		if (expand(&tokens->value, shell))
			return (1);
		else
			tokens = tokens->next;
	}
	// remove quotes
	return (0);
}

static int	expand(char **str, t_shell *shell)
{
	size_t	start;
	size_t	i;
	char	*res;
	int		quote;

	i = 0;
	start = 0;
	quote = 0;
	res = ft_strdup("");
	if (!res)
		return (1);
	while ((*str)[i])
	{
		quote = get_state((*str)[i], quote);
		if ((*str)[i] == '$' && quote != 1)
		{
			res = replace_exp(*str, res, start, i, shell);
			if (!res)
				return (free(res), 1);
			start = i;
		}
		i++;
	}
	if (res[0] == '\0')
		return (free(res), 0);
	if (start != i)
	{
		res = connect_str(res, ft_substr(*str, start, i - start));
		if (!res)
			return (1);
	}
	free(*str);
	*str = res;
	return (0);
}

static char	*replace_exp(char *str, char *res, size_t start, size_t i, t_shell *shell)
{
	char	*key;

	res = connect_str(res, ft_substr(str, start, i - start));
	if (!res)
		return (NULL);
	key = get_key_name(str, &i);
	if (!key)
		return (NULL);
	res = connect_exp(res, key, shell->ev);
	if (!res)
		return (free(key), free(res), NULL);
	free(key);
	return (res);
}

static char	*connect_exp(char *res, char *key, t_env *ev)
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


static int	get_state(char c, int quote)
{
	if (c == '\'' && quote == 0)
		return (1);
	if (c == '\'' && quote == 1)
		return (0);
	if (c == '"' && quote == 0)
		return (2);
	if (c == '"' && quote == 2)
		return (0);
	return (0);
}

