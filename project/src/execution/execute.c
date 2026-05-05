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
	if (!nodes->next && is_builtin(nodes->argv))
	{
		if (nodes->outfile)
			fd = ft_cf(nodes->outfile);
		status = run_builtin(nodes->argv, &shell->ev, fd);
		printf("-------%d--------\n", status);
		if (status)
			return ;
	}
	else
		status = ft_pipex(nodes, &shell->ev, nodes_len(nodes));
	shell->exit_status = status;
	//printf("execution ...\n");
}
