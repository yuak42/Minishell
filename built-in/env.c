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

int	ft_env(t_list *env)
{
	while (env)
	{
		if (ft_strchr(env->content, '='))
		{
			if(printf("%s\n", (char *)env->content) < 0)
			{
				perror("");
				return (1);
			}
		}
		env = env->next;
	}
	return (0);
}
// = içerenleri yazdırmayı ekle.
// -'yi sona alma durumuna bak.