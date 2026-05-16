/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 12:31:29 by yuak              #+#    #+#             */
/*   Updated: 2026/05/16 13:08:03 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

int	expand(char **str, t_shell *shell)
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
			res = replace_exp(*str, res, start, &i, shell);
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