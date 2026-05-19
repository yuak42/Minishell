/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-05 15:25:07 by byaprak           #+#    #+#             */
/*   Updated: 2026-05-05 15:25:07 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	execute(t_node *nodes, t_shell *shell)
{
	int status;
	int	fd;

	fd = 1;
	if (!nodes->next && ((!nodes->argv) || !nodes->argv[0] || nodes->argv[0][0] == '\0'))
	{
		if(!ft_redir(nodes))
		{
			perror("-minishell");
			status = 1;
		}
		else
			status = 0;
	}
	else if (!nodes->next && is_builtin(nodes->argv))
	{
		ft_redir(nodes);
		if (nodes->infile == -1)
		{
			perror("-minishell");
			shell->exit_status = 1;
			return ;
		}
		if (nodes->outfile)
			fd = nodes->outfile;
		status = run_builtin(nodes->argv, shell, fd);
	}
	else
		status = ft_pipex(nodes, shell, nodes_len(nodes));
	shell->exit_status = status;
}
