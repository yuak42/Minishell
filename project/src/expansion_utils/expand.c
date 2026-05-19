/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 12:31:29 by yuak              #+#    #+#             */
/*   Updated: 2026/05/19 18:41:48 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static char	*expand_loop(char *str, size_t *start, size_t *i, t_shell *shell);

int	expand(t_token *token, t_shell *shell)
{
	char	*expanded;

	if (token->value == NULL)
		return (0);
	printf("before\n");
	print_tokens(shell->tokens);
	if (token->prev && token->prev->type == token_heredoc)
		return (0);
	printf("after\n");
	expanded = get_expanded((token->value), shell);
	if (!expanded)
		return (1);
	free(token->value);
	token->value = expanded;
	return (0);
}

char	*get_expanded(char *str, t_shell *shell)
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
		if (!ft_isalpha(str[*i + 1]) && str[*i + 1] != '?')
		{
			(*i)++;
			continue ;
		}
		else if (str[*i] == '$' && quote != 1)
		{
			res = replace_exp(str, res, *start, i, shell);
			if (!res)
				return (NULL);
			*start = *i;
			continue ;
		}
		(*i)++;
	}
	return (res);
}
