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

int is_builtin(t_node *nodes, t_shell *shell)
{
	if (ft_strnstr(nodes->argv[0], "cd", ft_strlen(nodes->argv[0])))
		return (ft_cd(nodes->argv, shell->ev));
	else if (ft_strnstr(nodes->argv[0], "echo", ft_strlen(nodes->argv[0])))
		return (ft_echo(nodes->argv, shell->ev));
	else if (ft_strnstr(nodes->argv[0], "env", ft_strlen(nodes->argv[0])))
		return (ft_env(shell->ev));
	else if (ft_strnstr(nodes->argv[0], "export", ft_strlen(nodes->argv[0])))
		return (ft_export(nodes->argv, shell->ev));
	else if (ft_strnstr(nodes->argv[0], "pwd", ft_strlen(nodes->argv[0])))
		return (ft_pwd());
	else if (ft_strnstr(nodes->argv[0], "unset", ft_strlen(nodes->argv[0])))
		return (ft_unset(nodes->argv, &shell->ev));
	else
		return (0);
}
