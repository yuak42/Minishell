/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:22 by yuak              #+#    #+#             */
/*   Updated: 2026/05/10 15:32:18 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	basic_prompt(t_shell *shell)
{
	char	*line;

	while (1)
	{
		line = readline("$ ");
		if (!line)
			break ;
		if (*line && !is_only_spaces(line))
			add_history(line);
		shell->tokens = tokenizer(line, shell);
		printf("-----before expansion----\n");
		print_tokens(shell->tokens);
		printf("\n----after expansion----\n");
		if (shell->tokens)
		{
			shell->nodes = create_nodes(shell->tokens);
			if (shell->nodes)
			{
				print_nodes(shell->nodes);
				execute(shell->nodes, shell);
				free_nodes(shell->nodes);
			}
		}
		free_tokens(shell->tokens);
		free(line);
	}
	rl_clear_history();
}
