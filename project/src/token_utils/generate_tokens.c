/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:48:35 by yuak              #+#    #+#             */
/*   Updated: 2026/05/10 20:41:26 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	is_delimeter(char c);

t_token	*generate_tokens(char *line)
{
	t_token	*tokens;
	t_token	*token;
	size_t	i;
	size_t	start;

	tokens = NULL;
	i = 0;
	start = 0;
	while (line[i])
	{
		if (is_delimeter(line[i]))
		{
			if (get_token(&tokens, line, &start, &i))
				return (free_tokens(tokens), NULL);
		}
		i++;
	}
	if (start != i)
	{
		token = create_token(line, start, i, ' ');
		if (!token)
			return (free_tokens(tokens), NULL);
		add_token_last(&tokens, token);
	}
	return (tokens);
}

static int	is_delimeter(char c)
{
	if (c == ' ' || c == '\t' || c == '"' || c == '\'')
		return (1);
	if (c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}
