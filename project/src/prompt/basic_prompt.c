/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:22 by yuak              #+#    #+#             */
/*   Updated: 2026/05/23 11:13:41 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	handle_input(t_shell *shell);

void	basic_prompt(t_shell *shell)
{
	char	*line;
	int		status;

	while (1)
	{
		line = prompt(shell);
		if (!line)
			break ;
		shell->line = line;
		status = handle_input(shell);
		if (status == 2)
			break ;
		else if (status == 1)
			continue ;
	}
	write(1, "exit\n", 5);
	rl_clear_history();
}

static int	handle_input(t_shell *shell)
{
	int		status;

	status = 0;
	if (shell->line[0] == '\0')
		return (free(shell->line), 0);
	add_history(shell->line);
	status = parser(shell);
	if (status == 1)
		return (1);
	else if (status == 2)
		return (status);
	execute(shell->nodes, shell);
	if (shell->exit_status == 131)
		print_error("Quit (core dumped)\n");
	free_parser(shell);
	g_signal = 0;
	return (status);
}
