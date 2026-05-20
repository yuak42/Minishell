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

static int	void_args(t_node *nodes)
{
	if (!ft_redir(nodes))
	{
		perror("-minishell");
		return (1);
	}
	else
		return (0);
}

static int	run_prompt(t_node *nodes, t_shell *shell, int fd)
{
	int	status;

	ft_redir(nodes);
	if (nodes->infile == -1)
	{
		perror("-minishell");
		return (1);
	}
	else if (nodes->outfile)
		fd = nodes->outfile;
	status = run_builtin(nodes->argv, shell, fd);
	return (status);
}

void	execute(t_node *nodes, t_shell *shell)
{
	int	status;
	int	fd;

	fd = 1;
	if (!nodes->next && ((!nodes->argv) || !nodes->argv[0]))
		status = void_args(nodes);
	else if (!nodes->next && is_builtin(nodes->argv))
		status = run_prompt(nodes, shell, fd);
	else
		status = ft_pipex(nodes, shell, nodes_len(nodes));
	shell->exit_status = status;
}
