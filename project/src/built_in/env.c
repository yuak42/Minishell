/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 18:54:59 by byaprak           #+#    #+#             */
/*   Updated: 2026/05/23 14:03:51 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

int	ft_env(t_env *ev, int fd)
{
	int	status;

	while (ev != NULL)
	{
		if (ev->value && ev->value[0])
		{
			status = ft_printf_fd(fd, "%s=%s\n", ev->key, ev->value);
			if (status < 0)
			{
				perror("-minishell");
				return (status);
			}
		}
		ev = ev->next;
	}
	return (status);
}
