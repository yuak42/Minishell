/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:35:34 by byaprak           #+#    #+#             */
/*   Updated: 2025/06/29 23:51:29 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*c;
	size_t		i;
	size_t		slen;

	slen = ft_strlen(s);
	i = 0;
	if (start > slen)
		return (ft_calloc(1, 1));
	if (len > (slen - start))
		len = slen - start;
	c = malloc(len + 1 * sizeof(char));
	if (!c)
		return (NULL);
	while (i < len)
	{
		c[i] = s[start];
		i++;
		start++;
	}
	c[len] = '\0';
	return (c);
}
