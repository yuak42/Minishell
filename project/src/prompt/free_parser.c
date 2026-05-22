/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:41:10 by yuak              #+#    #+#             */
/*   Updated: 2026/05/22 20:41:19 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	free_parser(t_shell *shell)
{
	free_nodes(shell->nodes);
	free_tokens(shell->tokens);
	free(shell->line);
}
