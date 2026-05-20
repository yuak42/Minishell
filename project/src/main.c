/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:52:51 by yuak              #+#    #+#             */
/*   Updated: 2026/05/20 12:23:20 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static t_shell	*init_shell(char **env);

int	main(int ac, char **av, char **env)
{
	t_shell	*shell;

	(void) ac;
	(void) av;
	shell = init_shell(env);
	if (!shell)
		return (1);
	set_interactive_signals();
	basic_prompt(shell);
	free_ev(shell->ev);
	free(shell);
	return (0);
}

static t_shell	*init_shell(char **env)
{
	t_shell	*shell;

	shell = (t_shell *) ft_calloc(1, sizeof(t_shell));
	if (!shell)
		return (NULL);
	shell->ev = get_env_list(env);
	if (!shell->ev)
		return (NULL);
	return (shell);
}
