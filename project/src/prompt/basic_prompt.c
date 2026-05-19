/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:22 by yuak              #+#    #+#             */
/*   Updated: 2026/05/19 09:39:29 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static char	*prompt(void);

void	basic_prompt(t_shell *shell)
{
	char	*line;

	while (1)
	{
		line = prompt();
		if (!line)
			break ;
		else if (line[0] == '\0')
		{
			free(line);
			continue ;
		}
		shell->line = line;
		shell->tokens = tokenizer(line, shell);
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

static char	*prompt(void)
{
	char	*line;
	char	*ret_empty;

	line = readline("$ ");
	if (!line)
		return (NULL);
	if (line[0] == '\0' || is_only_spaces(line))
	{
		ret_empty = ft_strdup("");
		if (!ret_empty)
			return (free(line), NULL);
		return (free(line), ret_empty);
	}
	add_history(line); // belki daha sonra (heredoc'tan) sonraya koyulabilir.
	return (line);
}