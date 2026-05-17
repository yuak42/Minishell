/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 14:32:43 by yuak              #+#    #+#             */
/*   Updated: 2026/05/17 15:51:43 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

volatile sig_atomic_t	g_exit_status = 0;

void	sigint_handler(int sig)
{
	(void) sig;
	g_exit_status = 130;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	set_interactive_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	set_child_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	heredoc_sigint(int sig)
{
	(void)sig;
	g_exit_status = 130;
	close(STDIN_FILENO);
}
