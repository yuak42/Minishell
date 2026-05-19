/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 09:53:55 by yuak              #+#    #+#             */
/*   Updated: 2026/05/19 11:20:54 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

int	heredoc(t_shell *shell)
{
	t_node	*head;
	t_redir	*redir;
	char	*str;
	int		p[2];
	
	pipe(p);
	head = shell->nodes;
	while (head)
	{
		redir = head->redir;
		while (redir)
		{
			if (redir->type == token_heredoc)
			{
				str = readline("> ");
				write(p[1], str, ft_strlen(str));
				redir->read = p[0];
				free(str);
			}
			redir = redir->next;
		}
		head = head->next;
	}
	return (0);
}
