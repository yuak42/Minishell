/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-17 13:46:16 by byaprak           #+#    #+#             */
/*   Updated: 2026-05-17 13:46:16 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

int	ft_redir (t_node *nodes)//, t_shell *shell)
{
	t_redir *head;
	int		infile;
	int		outfile;

	infile = 0;
	outfile = 0;

	head = nodes->redir;
	while (head)
	{
		if(head->type == token_redir_out)
		{
			if (outfile > 2)
				close(outfile);
			outfile = ft_cf(head->file);
		}
		else if(head->type == token_redir_in)
		{
			if (infile > 2)
				close(infile);
			infile = ft_of(head->file);
		}
		else if(head->type == token_redir_app)
		{
			if (outfile)
				close(outfile);
			outfile = ft_af(head->file);
		}
		else if (head->type == token_heredoc)
		{
			if (head->read)
			{
				if (infile > 2)
					close (infile);
				infile = head->read;
			}
		}
		if(infile == -1 || outfile == -1)
		{
			break ;
		// 	perror("minishell");
		// 	free_nodes(nodes);
		// 	free_tokens(shell->tokens);
		// 	free(shell->line);
		// 	free_ev(shell->ev);
		// 	exit(1);
		}
		head = head->next;
	}
	nodes->infile = infile;
	nodes->outfile = outfile;
	if(infile == -1 || outfile == -1)
		return (0);
	return (1);
}
