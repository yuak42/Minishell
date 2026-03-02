/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:55:48 by yuak              #+#    #+#             */
/*   Updated: 2025/07/03 12:24:10 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*temp_s;
	char			*temp;
	unsigned char	uc;

	temp_s = (unsigned char *) s;
	uc = (unsigned char) c;
	temp = NULL;
	while (*temp_s != '\0')
	{
		if (*temp_s == uc)
			temp = (char *) temp_s;
		temp_s++;
	}
	if (uc == '\0')
		return ((char *) temp_s);
	return (temp);
}
