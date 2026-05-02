/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-30 18:54:59 by byaprak           #+#    #+#             */
/*   Updated: 2026-03-30 18:54:59 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_env(t_env *ev)
{
	int	status;

	while (ev != NULL)
	{
		status = printf("%s=%s\n", ev->key, ev->value);
		if (status < 0)
		{
			perror("-minishell");
			return (status);
		}
		ev = ev->next;
	}
}
// = içerenleri yazdırmayı ekle.
// -'yi sona alma durumuna bak.