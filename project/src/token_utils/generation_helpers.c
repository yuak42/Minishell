/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generation_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:05 by yuak              #+#    #+#             */
/*   Updated: 2026/05/10 15:30:03 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	normal(t_token **tokens, char *line, size_t *s, size_t *i);
static int	quote(t_token **tokens, char *line, size_t *s, size_t *i, char q);
static int	meta(t_token **tokens, char *line, size_t *s, size_t *i);

int	get_token(t_token **tokens, char *line, size_t *s, size_t *i)
{
	if (line[*i] == ' ')
	{
		if (normal(tokens, line, s, i))
			return (1);
	}
	else if (line[*i] == '\'' || line[*i] == '"')
	{
		if (quote(tokens, line, s, i, line[*i]))
			return (1);
	}
	else
	{
		if (meta(tokens, line, s, i))
			return (1);
	}
	return (0);
}

static int	normal(t_token **tokens, char *line, size_t *s, size_t *i)
{
	t_token	*token;

	token = create_token(line, *s, *i, ' ');
	if (!token)
		return (1);
	while (line[*i] == ' ' && line[*i] != '\0')
		(*i)++;
	(*i)--;
	*s = *i + 1;
	add_token_last(tokens, token);
	return (0);
}

static int	quote(t_token **tokens, char *line, size_t *s, size_t *i, char q)
{
	t_token	*token;

	(*i)++;
	(*s)++;
	while (line[*i] != '\0' && line[*i] != q)
		(*i)++;
	if (line[*i] == q)
	{
		token = create_token(line, *s, *i, q);
		if (!token)
			return (1);
	}
	else
	{
		ft_perror("syntax error!%s\n", "");
		return (1);
	}
	add_token_last(tokens, token);
	(*i)++;
	while (line[*i] == ' ' && line[*i] != '\0')
		(*i)++;
	(*i)--;
	*s = *i + 1;
	return (0);
}

static int	meta(t_token **tokens, char *line, size_t *s, size_t *i)
{
	t_token	*token;

	token = get_meta_token(&line[*i], i);
	add_token_last(tokens, token);
	*s = (*i) + 1;
	return (0);
}
