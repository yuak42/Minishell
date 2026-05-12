/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:54 by yuak              #+#    #+#             */
/*   Updated: 2026/05/12 09:38:05 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	expand(char **value, t_shell *shell);
int	get_state(char c, int quote);
int	connect_str(char *res, char *conn);

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
	return (0);
}

static int	expand(char **value, t_shell *shell)
{
	size_t	i;
	char	*str;
	int		quote;
	size_t	start;
	char	*final;
	char	*temp;
	(void) shell;
	i = 0;
	quote = 0;
	start = 0;
	str = *value;
	final = ft_strdup("");
	temp = NULL;
	while (str[i])
	{
		quote = get_state(str[i], quote);
		// if (quote == 0)
		// {
		// 	if (str[i] != '$')
		// 		new_str[i] = str[i];
		// 	else
		// 		fill_exp(new_str, str, i);
		// 	start = i + 1;
		// }
		// else if (quote == 2 && str[i] != '"')
		// {
		// 	if (str[i] != '$')
		// 		new_str[i] = str[i];
		// 	else
		// 		fill_exp(new_str, str, i);
		// 	start = i + 1;
		// }
		// else
		if (quote == 1 && str[i] != '\'')
		{
			while (str[i] && quote == 1)
			{
				i++;
				quote = get_state(str[i], quote);
			}
			temp = ft_substr(str, start, i - start);
			if (!temp)
				return (free(final), -1);
			if (connect_str(final, temp))
				return (free(final), -1);
			start = i + 1;
		}
		i++;
	}
	if (str[i] == '\0')
	{
		free(*value);
		*value = final;
		return (0);
	}
	return (1);
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
	return (1);
}

// void	fill_exp(char **value, size_t i, t_shell *shell)
// {
// 	(void) value;
// 	(void) i;
// 	(void) shell;
// }

int	connect_str(char *res, char *conn)
{
	char	*final;
	
	final = ft_strjoin(res, conn);
	if (!final)
		return (1);
	free(res);
	final = res;
	return (0);
}