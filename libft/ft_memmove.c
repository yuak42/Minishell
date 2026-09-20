/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:49:29 by byaprak           #+#    #+#             */
/*   Updated: 2025/06/29 18:36:07 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!src && !dest)
		return (dest);
	d = (char *)dest;
	s = (char *)src;
	if (d < s)
		ft_memcpy(dest, s, n);
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
