/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:29:15 by yuak              #+#    #+#             */
/*   Updated: 2025/07/01 14:43:31 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_in_set(char c, const char *set);
static size_t	find_size(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*str;
	size_t	size;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	size = find_size(s1, set);
	str = (char *) malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*s1 && is_in_set(*s1, set))
		s1++;
	while (*s1 && i < size)
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	find_size(char const *s1, char const *set)
{
	size_t	dec_size;
	size_t	i;

	i = 0;
	dec_size = 0;
	while (is_in_set(s1[i], set))
	{
		dec_size++;
		i++;
	}
	if (s1[i] == '\0')
		return (ft_strlen(s1) - dec_size);
	while (s1[i])
		i++;
	i--;
	while (is_in_set(s1[i], set))
	{
		dec_size++;
		i--;
	}
	return (ft_strlen(s1) - dec_size);
}
