/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:54:17 by yuak              #+#    #+#             */
/*   Updated: 2026/05/20 14:56:10 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

int	is_delimeter(char *line, char *delim)
{
	size_t	line_len;
	size_t	delim_len;

	line_len = ft_strlen(line);
	delim_len = ft_strlen(delim);
	if (line_len == delim_len && !ft_strncmp(line, delim, line_len))
		return (1);
	return (0);
}

void	no_eof_delimeter(int *p, t_redir *redir)
{
	print_error("minishell: warning: here-document ");
	ft_perror("delimited by end-of-file (wanted `%s`)\n", redir->file);
	close(p[1]);
	redir->read = p[0];
}

int	write_for_heredoc(int *p, char *str)
{
	int	ret;

	ret = write(p[1], str, ft_strlen(str));
	if (ret == -1)
		return (1);
	ret = write(p[1], "\n", 1);
	if (ret == -1)
		return (1);
	return (0);
}
