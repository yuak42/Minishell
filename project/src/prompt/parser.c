/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:44:46 by yuak              #+#    #+#             */
/*   Updated: 2026/05/23 00:00:39 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

int	parser(t_shell *shell)
{
	int	status;

	status = tokenizer(shell->line, shell);
	if (status == 2)
		return (free(shell->line), 2);
	if (status == 0)
	{
		shell->nodes = create_nodes(shell->tokens);
		if (!shell->nodes)
			return (free_tokens(shell->tokens), free(shell->line), 2);
		status = heredoc(shell);
		if (status == 2)
			return (free_parser(shell), 2);
		if (status == 130)
			return (free_parser(shell), 1);
	}
	else
		return (free(shell->line), 1);
	return (0);
}
