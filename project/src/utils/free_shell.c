/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 19:47:28 by yuak              #+#    #+#             */
/*   Updated: 2026/05/23 09:55:07 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	free_shell(t_shell *shell)
{
	free_nodes(shell->nodes);
	free_tokens(shell->tokens);
	free(shell->line);
	free_ev(shell->ev);
	free(shell);
}
