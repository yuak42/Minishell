/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:05 by yuak              #+#    #+#             */
/*   Updated: 2026/05/17 19:31:53 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static size_t	get_end_of_word(char *line);
static int			is_metachar(char c);

t_token	*get_word(char *line, size_t *i)
{
	t_token	*token;
	size_t	j;

	token = (t_token *) ft_calloc(1, sizeof(t_token));
	if (!token)
		return (print_error("Error: ft_calloc\n"), NULL);
	j = get_end_of_word(&line[*i]);
	token->value = ft_substr(line, *i, j);
	if (!token->value)
		return (free(token), NULL);
	token->type = token_word;
	token->next = NULL;
	*i = *i + j;
	return (token);
}

static size_t	get_end_of_word(char *line)
{
	size_t	j;

	j = 0;
	while (line[j])
	{
		if (line[j] == '"')
		{
			j++;
			while (line[j] && line[j] != '"')
				j++;
		}
		if (line[j] == '\'')
		{
			j++;
			while (line[j] && line[j] != '\'')
				j++;
		}
		if (is_metachar(line[j]) || line[j] == '\0')
			return (j);		
		j++;
	}
	return (j);
}

static int	is_metachar(char c)
{
	if (c == ' ' || c == '\t' || c == '<')
		return (1);
	if (c == '>' || c == '|')
		return (1);
	return (0);
}

static t_token_type	get_operator_type(char *line, size_t *j);

t_token	*get_operator(char *line, size_t *i)
{
	t_token	*token;
	size_t	j;

	j = *i;
	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		return (print_error("Error: ft_calloc\n"), NULL);
	token->type = get_operator_type(line, &j);
	token->next = NULL;
	*i = j;
	return (token);
}

static t_token_type	get_operator_type(char *line, size_t *j)
{
	if (!ft_strncmp(&line[*j], ">>", 2))
	{
		*j += 2;
		return (token_redir_app);
	}
	if (!ft_strncmp(&line[*j], "<<", 2))
	{
		*j += 2;
		return (token_heredoc);
	}
	if (line[*j] == '>')
		return ((*j)++, token_redir_out);
	if (line[*j] == '<')
		return ((*j)++, token_redir_in);
	(*j)++;
	return (token_pipe);
}

