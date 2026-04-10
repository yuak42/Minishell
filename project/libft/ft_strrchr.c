/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:13:07 by byaprak           #+#    #+#             */
/*   Updated: 2025/06/29 23:51:18 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	if (c > 256)
		c = c % 256;
	p = (char *)s;
	p += ft_strlen(s);
	while (p >= s)
	{
		if (*p == c)
			return (p);
		p--;
	}
	return (NULL);
}
