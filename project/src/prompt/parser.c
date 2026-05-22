/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:44:46 by yuak              #+#    #+#             */
/*   Updated: 2026/05/22 20:44:58 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

int	parser(t_shell *shell)
{
	shell->tokens = tokenizer(shell->line, shell);
	if (shell->exit_status == 2)
		return (free(shell->line), 2);
	if (shell->tokens)
	{
		shell->nodes = create_nodes(shell->tokens);
		if (!shell->nodes)
		{
			free_tokens(shell->tokens);
			return (free(shell->line), 1);
		}
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