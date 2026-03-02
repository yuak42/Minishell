/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:33:25 by yuak              #+#    #+#             */
/*   Updated: 2025/06/12 18:55:10 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	uc;

	uc = (unsigned char) c;
	temp = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		temp[i] = uc;
		i++;
	}
	return (s);
}
