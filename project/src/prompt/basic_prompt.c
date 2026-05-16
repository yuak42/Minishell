/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:22 by yuak              #+#    #+#             */
/*   Updated: 2026/05/16 19:22:30 by yuak             ###   ########.fr       */
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
		if (!*line)
		{
    		free(line);
    		continue;  // tokenizer, execute gibi kodları atla, sonraki while iterasyonuna git
		}
		shell->line = line;
		shell->tokens = tokenizer(line, shell);
		if (shell->tokens)
		{
			shell->nodes = create_nodes(shell->tokens);
			if (shell->nodes)
			{
				// print_nodes(shell->nodes);
				execute(shell->nodes, shell);
				free_nodes(shell->nodes);
			}
		}
		free_tokens(shell->tokens);
		free(line); // always free at the end of loop
	}
	rl_clear_history();
}
