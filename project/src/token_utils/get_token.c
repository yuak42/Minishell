/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:05 by yuak              #+#    #+#             */
/*   Updated: 2026/05/17 19:22:41 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	is_metachar(char c);
size_t	get_end_of_word(char *line);

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

size_t	get_end_of_word(char *line)
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

t_token	*get_operator(char *line, size_t *i)
{
	t_token	*token;
	size_t	j;

	j = *i;
	token = (t_token *) ft_calloc(1, sizeof(t_token));
	if (!token)
		return (print_error("Error: ft_calloc\n"), NULL);
	if (!ft_strncmp(&line[j], ">>", 2))
	{
		token->type = token_redir_app;
		j = j + 2;
	}
	else if (!ft_strncmp(&line[j], "<<", 2))
	{
		token->type = token_heredoc;
		j = j + 2;
	}
	else if (line[j] == '>')
	{
		token->type = token_redir_out;
		j++;
	}
	else if (line[j] == '<')
	{
		token->type = token_redir_in;
		j++;
	}
	else
	{
		token->type = token_pipe;
		j++;
	}
	*i = j;
	return (token);
}

static int	is_metachar(char c)
{
	if (c == ' ' || c == '\t' || c == '<')
		return (1);
	if (c == '>' || c == '|')
		return (1);
	return (0);
}
