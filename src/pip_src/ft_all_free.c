/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 08:09:11 by byaprak           #+#    #+#             */
/*   Updated: 2026/05/23 14:01:29 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	ft_all_free(t_pipe plist)
{
	free_nodes(plist.node);
	free_tokens(plist.shell->tokens);
	free(plist.shell->line);
	free_ev(plist.shell->ev);
}
