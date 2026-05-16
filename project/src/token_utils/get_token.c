/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:05 by yuak              #+#    #+#             */
/*   Updated: 2026/05/15 13:06:18 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	is_metachar(char c);

t_token	*get_word(char *line, size_t *i)
{
	t_token	*token;
	size_t	start;
	size_t	j;
	int		quote;

	j = (*i);
	if (line[j] == '\'')
		quote = 1;
	else if (line[j] == '"')
		quote = 2;
	else
		quote = 0;
	token = (t_token *) ft_calloc(1, sizeof(t_token));
	if (!token)
		return (print_error("Error: ft_calloc\n"), NULL);
	start = j;
	j++;
	if (quote == 1)
	{
		while (quote == 1 || (!is_metachar(line[j]) && line[j] != '\0'))
		{
			if (line[j] == '\'')
				quote = 0;
			if (line[j] == '\0')
				break ;
			j++;
		}
	}
	else if (quote == 2)
	{
		while (quote == 2 || (!is_metachar(line[j]) && line[j] != '\0'))
		{
			if (line[j] == '"')
				quote = 0;
			if (line[j] == '\0')
				break ;
			j++;
		}
	}
	else
	{
		while (!is_metachar(line[j]) && line[j] != '\0')
			j++;
	}
	*i = j;
	token->value = ft_substr(line, start, j - start);
	if (!token->value)
		return (free(token), NULL);
	token->type = token_word;
	token->next = NULL;
	return (token);
}

t_token *get_operator(char *line, size_t *i)
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
