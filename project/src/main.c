/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:52:51 by yuak              #+#    #+#             */
/*   Updated: 2026/05/10 12:41:44 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

int	main(int ac, char **av, char **env)
{
	t_shell	*shell;

	(void) ac;
	(void) av;
	shell = (t_shell *) ft_calloc(1, sizeof(t_shell));
	if (!shell)
		return (1);
	shell->ev = get_env_list(env);
	if (!shell->ev)
		return (1);
	basic_prompt(shell);
	free_ev(shell->ev);
	free(shell);
	return (0);
}
