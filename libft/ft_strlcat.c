/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:50:24 by byaprak           #+#    #+#             */
/*   Updated: 2025/06/29 23:50:50 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	dlen;
	size_t	i;
	size_t	j;
	size_t	slen;

	slen = ft_strlen(src);
	j = n - ft_strlen(dst) -1;
	i = 0;
	dlen = ft_strlen(dst);
	if (n <= dlen)
		return (n + slen);
	while (src[i] != '\0' && j--)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (slen + dlen);
}
