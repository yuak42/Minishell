/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:42:09 by yuak              #+#    #+#             */
/*   Updated: 2026/05/22 20:45:51 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

char	*prompt(t_shell *shell)
{
	char	*line;
	char	*ret_empty;

	line = readline("msh$ ");
	if (g_signal != 0)
		shell->exit_status = 128 + g_signal;
	if (!line)
		return (NULL);
	if (line[0] == '\0' || is_only_spaces(line))
	{
		ret_empty = ft_strdup("");
		if (!ret_empty)
			return (free(line), NULL);
		return (free(line), ret_empty);
	}
	return (line);
}
