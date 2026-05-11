/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:54 by yuak              #+#    #+#             */
/*   Updated: 2026/05/11 20:50:43 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	expand(char **value, t_shell *shell);

int	expansion(t_shell *shell)
{
	int		state;
	t_token	*tokens;

	tokens = shell->tokens;
	while (tokens)
	{
		if (expand(&tokens->value, shell))
			continue ;
		else
			tokens = tokens->next;
	}
	return (0);
}

static int	expand(char **value, t_shell *shell)
{
	size_t	i;
	char	*str;
	int		state;

	i = 0;
	str = *value;
	state = 0;
	while (str[i])
	{
		if (state = 0 && str[i] == '\'')
			state = 1;
		else if (state = 1 && str[i] == '\'')
			state = 0;
		if (state == 0 && str[i] == '$')
			break ;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	replace(value, i, shell);
	return (1);
}

void	replace(char **value, size_t i, t_shell *shell)
{
	size_t	j;

	j = i;
	if (str[i + 1] != '_' && !ft_isalpha(str[i + 1]))
	{
		change_with_empty(value, i);
	}
}