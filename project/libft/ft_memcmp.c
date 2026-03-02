/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:41:47 by yuak              #+#    #+#             */
/*   Updated: 2025/07/03 13:26:04 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;
	size_t			i;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (temp_s1[i] != temp_s2[i])
			return ((int)(temp_s1[i] - temp_s2[i]));
		i++;
	}
	return (0);
}
