/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:48:35 by yuak              #+#    #+#             */
/*   Updated: 2026/05/11 15:41:18 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	is_delimeter(char c);
static void	skip_current(char *line, size_t *i);

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
			if (!tokens)
			{
				token = get_token(line, start, i);
				if (!token)
					return (free_tokens(tokens), NULL);
			}
			else
			{
				token = get_token(line, start, i);
				if (!token)
					return (free_tokens(tokens), NULL);
			}
			add_token_last(&tokens, token);
			skip_current(line, &i);
			start = i;
			continue ;
		}
		i++;
	}
	if (start != i)
	{
		if (!tokens)
		{
			token = get_token(line, start, i);
			if (!token)
				return (free_tokens(tokens), NULL);
		}
		else
		{
			token = get_token(line, start, i);
			if (!token)
				return (free_tokens(tokens), NULL);
		}
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

static void	skip_current(char *line, size_t *i)
{
	size_t	j;

	j = *i;
	if (line[j] == ' ' || line[j] == '\t')
	{
		while (line[j] == ' ' || line[j] == '\t')
			j++;
	}
	else if (line[j] == '"')
	{
		j++;
		while (line[j] != '"' && line[j] != '\0')
			j++;
		j++;
		while (line[j] == ' ' && line[j] != '\0')
			j++;		
	}
	else if (line[j] == '\'')
	{
		j++;
		while (line[j] != '\'' && line[j] != '\0')
			j++;
		j++;
	}
	*i = j;
}