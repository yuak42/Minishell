/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:44:06 by yuak              #+#    #+#             */
/*   Updated: 2025/06/28 12:32:46 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	unsigned char	*temp;

	temp = (unsigned char *) s;
	uc = (unsigned char) c;
	while (*temp != uc)
	{
		if (*temp == '\0')
			return (NULL);
		temp++;
	}
	return ((char *) temp);
}
