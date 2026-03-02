/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:05:32 by yuak              #+#    #+#             */
/*   Updated: 2025/07/03 12:23:57 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp_1;
	unsigned char	*temp_2;

	temp_1 = (unsigned char *) s1;
	temp_2 = (unsigned char *) s2;
	i = 0;
	while (i < n && temp_1[i] && temp_2[i] && temp_1[i] == temp_2[i])
		i++;
	if (i == n)
		return (0);
	return ((int)(temp_1[i] - temp_2[i]));
}
