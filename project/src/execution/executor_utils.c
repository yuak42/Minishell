/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-01 23:16:11 by byaprak           #+#    #+#             */
/*   Updated: 2026-05-01 23:16:11 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"prompt.h"

int	is_builtin(t_node *nodes, t_shell *shell)
{
	if (ft_strnstr(nodes->argv[0], "cd", 2) && ft_strlen(nodes->argv[0]) == 2)
		return (ft_cd(nodes->argv, shell->ev));
	else if (ft_strnstr(nodes->argv[0], "echo", 4) && ft_strlen(nodes->argv[0]) == 4)
		return (ft_echo(nodes->argv, shell->ev));
	else if (ft_strnstr(nodes->argv[0], "env", 3) && ft_strlen(nodes->argv[0]) == 3)
		return (ft_env(shell->ev));
	else if (ft_strnstr(nodes->argv[0], "export", 6) && ft_strlen(nodes->argv[0]) == 6)
		return (ft_export(nodes->argv, shell->ev));
	else if (ft_strnstr(nodes->argv[0], "pwd", 3) && ft_strlen(nodes->argv[0]) == 3)
		return (ft_pwd());
	else if (ft_strnstr(nodes->argv[0], "unset", 5) && ft_strlen(nodes->argv[0]) == 5)
		return (ft_unset(nodes->argv, &shell->ev));
	else
		return (0);
}
