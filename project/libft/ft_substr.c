/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:38:31 by yuak              #+#    #+#             */
/*   Updated: 2025/07/01 14:38:28 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_len(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	sub = (char *) malloc((find_len(s, start, len) + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

static size_t	find_len(char const *s, unsigned int start, size_t len)
{
	size_t	size;

	size = 0;
	while (s[start] && size < len)
	{
		start++;
		size++;
	}
	return (size);
}
