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

<<<<<<< HEAD:project/built_in/env.c
void	ft_env(t_env *ev)
=======
int	ft_env(t_list *env)
>>>>>>> built-in:built-in/env.c
{
	while (ev != NULL)
	{
<<<<<<< HEAD:project/built_in/env.c
		printf("%s=%s\n", ev->key, ev->value);
		ev = ev->next;
=======
		if (ft_strchr(env->content, '='))
		{
			if(printf("%s\n", (char *)env->content) < 0)
			{
				perror("");
				return (1);
			}
		}
		env = env->next;
>>>>>>> built-in:built-in/env.c
	}
	return (0);
}
// = içerenleri yazdırmayı ekle.
// -'yi sona alma durumuna bak.