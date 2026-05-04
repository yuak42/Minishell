/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-03 21:21:11 by byaprak           #+#    #+#             */
/*   Updated: 2026-05-03 21:21:11 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	free_str(char **env, int i)
{
	if (i == -1)
	{
		i = 0;
		while (env[i])
		{
			free(env[i]);
			i++;
		}
	}
	else
	{
		while(i >= 0)
			{
				free(env[i]);
				i--;
			}
		}
	free(env);
}