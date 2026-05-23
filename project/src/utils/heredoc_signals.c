/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_signals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:50:28 by yuak              #+#    #+#             */
/*   Updated: 2026/05/23 07:42:32 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	heredoc_sigint_handler(int sig)
{
	write(1, "\n", 1);
	close(0);
	g_signal = sig;
}

void	set_heredoc_signals(void)
{
	signal(SIGINT, heredoc_sigint_handler);
}
