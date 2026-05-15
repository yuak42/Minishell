/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:54 by yuak              #+#    #+#             */
/*   Updated: 2026/05/15 15:58:40 by yuak             ###   ########.fr       */
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

static int	expand(char **value, t_shell *shell)
{
	size_t	i;
	int		quote;
	size_t	start;
	char	*final;

	i = 0;
	quote = 0;
	start = 0;
	final = ft_strdup("");
	while ((*value)[i])
	{
		quote = get_state((*value)[i], quote);	
		if ((*value)[i] == '$' && quote == 0)
		{
			key = get_key(*value, &i, shell);
			if (!key)
				return (NULL);
			final = connect_str(final, ft_substr(*value, start, i - start));
			if (!final)
				return (1);
			final = connect_expansion(final, *value, i, shell);
			if (!final)	
				return (1);
			start = i; // should go end of the expansion
		}
		i++;
	}
	if (final[0] == '\0')
		return (free(final), 0);
	free(*value);
	*value = final;
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

