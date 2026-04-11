/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-07 19:37:21 by byaprak           #+#    #+#             */
/*   Updated: 2026-04-07 19:37:21 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_getenv(t_list *ev, char *av)
{
	char	*str;
	char	*equals;

	while (ev)
	{
		str = ft_strnstr(ev->content, av, ft_strlen(av));
		if (str)
		{
			equals = (str + ft_strlen(av));
			if (!ft_strncmp(equals, "=", 1))
				return (ev);
		}
		ev = ev->next;
	}
	return (NULL);
}
