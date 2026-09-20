/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-02 23:00:27 by byaprak           #+#    #+#             */
/*   Updated: 2026-05-02 23:00:27 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

int	ft_env_size(t_env *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
