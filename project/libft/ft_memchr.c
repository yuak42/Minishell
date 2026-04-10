/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:26:23 by byaprak           #+#    #+#             */
/*   Updated: 2025/06/29 23:49:38 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*dst;
	unsigned char		*p;
	unsigned char		b;

	b = (unsigned char)c;
	dst = (unsigned char *)s;
	p = &b;
	while (n--)
	{
		if (*dst++ == *p)
			return ((void *)--dst);
	}
	return (NULL);
}
