/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:22 by yuak              #+#    #+#             */
/*   Updated: 2026/05/22 13:52:53 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static char	*prompt(t_shell *shell);
static int	parser(t_shell *shell);
static void	free_parser(t_shell *shell);

void	basic_prompt(t_shell *shell)
{
	char	*line;

	while (1)
	{
		line = prompt(shell);
		if (!line)
			break ;
		else if (line[0] == '\0')
		{
			free(line);
			continue ;
		}
		add_history(line);
		shell->line = line;
		if (parser(shell))
			continue ;
		execute(shell->nodes, shell);
		if (shell->exit_status == 131)
			print_error("Quit (core dumped)\n");
		free_parser(shell);
		g_signal = 0;
	}
	rl_clear_history();
}

static int	parser(t_shell *shell)
{
	shell->tokens = tokenizer(shell->line, shell);
	if (shell->tokens)
	{
		shell->nodes = create_nodes(shell->tokens);
		if (!shell->nodes)
		{
			free_tokens(shell->tokens);
			return (free(shell->line), 1);
		}
		print_nodes(shell->nodes);
		if (heredoc(shell))
		{
			free_parser(shell);
			return (1);
		}
	}
	else
		return (free(shell->line), 1);
	return (0);
}

static char	*prompt(t_shell *shell)
{
	char	*line;
	char	*ret_empty;

	line = readline("msh$ ");
	if (g_signal != 0)
		shell->exit_status = 128 + g_signal;
	if (!line)
		return (NULL);
	if (line[0] == '\0' || is_only_spaces(line))
	{
		ret_empty = ft_strdup("");
		if (!ret_empty)
			return (free(line), NULL);
		return (free(line), ret_empty);
	}
	return (line);
}

static void	free_parser(t_shell *shell)
{
	free_nodes(shell->nodes);
	free_tokens(shell->tokens);
	free(shell->line);
}
