/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_meta_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 14:24:16 by yuak              #+#    #+#             */
/*   Updated: 2026/05/10 15:30:10 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

t_token	*get_meta_token(char *s, size_t *i)
{
	t_token	*meta;

	meta = ft_calloc(1, sizeof(t_token));
	if (!meta)
		return (NULL);
	if (!ft_strncmp(s, ">>", 3))
	{
		meta->type = token_redir_app;
		(*i)++;
	}
	else if (!ft_strncmp(s, "<<", 3))
	{
		meta->type = token_heredoc;
		(*i)++;
	}
	else if (*s == '<')
		meta->type = token_redir_in;
	else if (*s == '>')
		meta->type = token_redir_out;
	else if (*s == '|')
		meta->type = token_pipe;
	return (meta);
}