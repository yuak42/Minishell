/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 12:31:29 by yuak              #+#    #+#             */
/*   Updated: 2026/05/16 15:00:53 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static char	*expand_loop(char *str, size_t *start, size_t *i, t_shell *shell);
static char	*get_expanded(char *str, t_shell *shell);

int	expand(char **str, t_shell *shell)
{
	char	*expanded;

	if (*str == NULL)
		return (0);
	expanded = get_expanded(*str, shell);
	if (!expanded)
		return (1);
	free(*str);
	*str = expanded;
	return (0);
}

static char	*get_expanded(char *str, t_shell *shell)
{
	size_t	i;
	size_t	start;
	char	*res;
	
	start = 0;
	i = 0;
	res = expand_loop(str, &start, &i, shell);
	if (!res)
		return (NULL);
	if (start != i)
	{
		res = connect_str(res, ft_substr(str, start, i - start));
		if (!res)
			return (NULL);
	}
	return (res);
}

static char	*expand_loop(char *str, size_t *start, size_t *i, t_shell *shell)
{
	char	*res;
	int		quote;

	quote = 0;
	res = ft_strdup("");
	if (!res)
		return (NULL);
	while (str[*i])
	{
		quote = get_state(str[*i], quote);
		if (str[*i] == '$' && quote != 1)
		{
			res = replace_exp(str, res, *start, i, shell);
			if (!res)
				return (NULL);
			*start = *i;
		}
		(*i)++;
	}
	return (res);
}