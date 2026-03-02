/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:21:14 by yuak              #+#    #+#             */
/*   Updated: 2025/06/28 12:45:16 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*temp;
	size_t				i;
	unsigned char		uc;

	temp = (const unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (temp[i] == uc)
			return ((void *)(temp + i));
		i++;
	}
	return (NULL);
}
