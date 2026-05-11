/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:05 by yuak              #+#    #+#             */
/*   Updated: 2026/05/11 15:10:44 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int assign_quote_token(t_token *token, char *line, size_t s, size_t i);

t_token	*get_token(char *line, size_t start, size_t i)
{
	t_token	*token;

	token = (t_token *) ft_calloc(1, sizeof(t_token));
	if (!token)
		return (print_error("Error: ft_calloc\n"), NULL);
	if (line[i] == ' ' || line[i] == '\0')
	{
		token->value = ft_substr(line, start, i - start);
		token->type = token_word;
		token->state = state_normal;
	}
	else if (line[i] == '"' || line[i] == '\'')
	{
		if (assign_quote_token(token, line, start, i))
		{
			free(token);
			return (NULL);
		}
	}
	else
	{
		print_error("Error: syntax error\n");
		free(token);
		return (NULL);
	}
	token->next = NULL;
	return (token);
}

static int assign_quote_token(t_token *token, char *line, size_t s, size_t i)
{
	char	q;

	q = line[i];
	i++;
	while (line[i] != q && line[i] != '\0')
		i++;
	if (line[i] == q)
	{
		token->value = ft_substr(line, s + 1, i - s - 1);
		if (!token->value)
			return (print_error("Error: ft_substr\n"), 1);
		token->type = token_word;
		if (q == '"')
			token->state = state_quote_double;
		else
			token->state = state_quote_single;
	}
	else
	{
		print_error("Error: syntax error\n");
		return (1);
	}
	return (0);
}