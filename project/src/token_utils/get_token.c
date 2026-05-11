/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:05 by yuak              #+#    #+#             */
/*   Updated: 2026/05/11 16:13:45 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	assign_quote_token(t_token *token, char *line, size_t s, size_t i);
static int	assign_operator(t_token *token, char *line, size_t s, size_t i);

t_token	*get_token(char *line, size_t start, size_t i)
{
	t_token	*token;

	token = (t_token *) ft_calloc(1, sizeof(t_token));
	if (!token)
		return (print_error("Error: ft_calloc\n"), NULL);
	if (line[i] == ' ' || line[i] == '\0' || line[i] == '>')
	{
		token->value = ft_substr(line, start, i - start);
		token->type = token_word;
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
		if (assign_operator(token, line, start, i))
		{
			free(token);
			return (NULL);
		}
	}
	token->next = NULL;
	return (token);
}

static int	assign_quote_token(t_token *token, char *line, size_t s, size_t i)
{
	i++;
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	token->value = ft_substr(line, s, i - s);
	if (!token->value)
		return (print_error("Error: ft_substr\n"), 1);
	token->type = token_word;
	return (0);
}

static int	assign_operator(t_token *token, char *line, size_t s, size_t i)
{
	// burada oncesini ayıracak

	
	if (!ft_strncmp(&line[i], ">>", 2))
		token->type = token_redir_out;
	else if (!ft_strncmp(&line[i], "<<", 2))
		token->type = token_heredoc;
	else if (line[i] == '>')
		token->type = token_redir_out;
	else if (line[i] == '<')
		token->type = token_redir_in;
	else
		token->type = token_pipe;
	(void) s;
	return (0);
	// burada sonrasini da ayiracak
}