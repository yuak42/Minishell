/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:05 by yuak              #+#    #+#             */
/*   Updated: 2026/05/11 16:51:55 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

// static int	assign_operator(t_token *token, char *line, size_t s, size_t i);
static int	is_metachar(char c);


t_token	*get_word(char *line, size_t *i)
{
	t_token	*token;
	size_t	start;
	size_t	j;

	j = (*i);
	token = (t_token *) ft_calloc(1, sizeof(t_token));
	if (!token)
		return (print_error("Error: ft_calloc\n"), NULL);
	start = j;
	while (!is_metachar(line[j]) && line[j] != '\0')
		j++;
	token->value = ft_substr(line, start, j - start);
	token->type = token_word;
	token->next = NULL;
	*i = j;
	return (token);
}

// static int	assign_operator(t_token *token, char *line, size_t s, size_t i)
// {
// 	if (!ft_strncmp(&line[i], ">>", 2))
// 		token->type = token_redir_out;
// 	else if (!ft_strncmp(&line[i], "<<", 2))
// 		token->type = token_heredoc;
// 	else if (line[i] == '>')
// 		token->type = token_redir_out;
// 	else if (line[i] == '<')
// 		token->type = token_redir_in;
// 	else
// 		token->type = token_pipe;
// 	(void) s;
// 	return (0);
// }

static int	is_metachar(char c)
{
	if (c == ' ' || c == '\t' || c == '<')
		return (1);
	if (c == '>' || c == '|')
		return (1);
	return (0);
}
