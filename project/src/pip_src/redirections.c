/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-17 13:46:16 by byaprak           #+#    #+#             */
/*   Updated: 2026-05-17 13:46:16 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	in_redir(t_redir *redir, int infile)
{
	int	i_file;

	if (redir->type == token_redir_in)
	{
		if (infile > 2)
			close(infile);
		i_file = ft_of(redir->file);
	}
	else if (redir->type == token_heredoc)
	{
		if (redir->read)
		{
			if (infile > 2)
				close (infile);
			i_file = redir->read;
		}
	}
	return (i_file);
}

static int out_redir(t_redir *redir, int outfile)
{
	int	o_file;

	if (redir->type == token_redir_out)
	{
		if (outfile > 2)
			close(outfile);
		o_file = ft_cf(redir->file);
	}
	else if (redir->type == token_redir_app)
	{
		if (outfile)
			close(outfile);
		o_file = ft_af(redir->file);
	}
	return (o_file);
}

int	ft_redir(t_node *nodes)
{
	t_redir	*head;
	int		infile;
	int		outfile;

	infile = 0;
	outfile = 0;
	head = nodes->redir;
	while (head)
	{
		if (head->type == token_redir_out || head->type == token_redir_app)
			outfile = out_redir(nodes->redir, outfile);
		else if (head->type == token_redir_in || head->type == token_heredoc)
			infile = in_redir(nodes->redir, infile);
		if (infile == -1 || outfile == -1)
			break ;
		head = head->next;
	}
	nodes->infile = infile;
	nodes->outfile = outfile;
	if (infile == -1 || outfile == -1)
		return (0);
	return (1);
}
