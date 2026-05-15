/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:54 by yuak              #+#    #+#             */
/*   Updated: 2026/05/15 19:37:19 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	expand(char **value, t_shell *shell);
static int	get_state(char c, int quote);

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
	char	*key;

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
			// add first part to res
			key = get_key(*str, &i, shell);
			replace(&res, key, shell->ev);
			// find expansion value
			// add expansion value
			start = i;
		}
		i++;
	}
	if (res[0] == '\0')
		return (free(res), 0);
	if (start != i)
	{
		// add remaining part to res
	}
	return (0);
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

