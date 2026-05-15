/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:48:35 by yuak              #+#    #+#             */
/*   Updated: 2026/05/15 11:13:27 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	is_operator(char c);

t_token	*generate_tokens(char *line)
{
	t_token	*tokens;
	t_token	*token;
	size_t	i;

	tokens = NULL;
	i = 0;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (!line[i])
			break ;
		if (is_operator(line[i]))
			token = get_operator(line, &i);
		else
			token = get_word(line, &i);
		if (!token)
			return (free_tokens(tokens), NULL);
		add_token_last(&tokens, token);
	}
	return (tokens);
}

static int	is_operator(char c)
{
	if (c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}
