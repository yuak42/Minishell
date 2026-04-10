/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 19:41:32 by byaprak           #+#    #+#             */
/*   Updated: 2025/06/29 23:50:28 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_splitlen(char const *s, char c)
{
	size_t		len;

	len = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			len++;
		while (*s && *s != c)
			s++;
	}
	return (len);
}

static void	ft_leakhount(char **split, size_t i)
{
	while (i--)
	{
		free(split[i]);
	}
	free(split);
}

static int	ft_splitwrite(char const *s, char **split, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c)
			s++;
		if (!*s)
			break ;
		while (s[len] && s[len] != c)
			len++;
		split[i] = ft_substr(s, 0, len);
		if (!split[i])
		{
			ft_leakhount(split, i);
			return (0);
		}
		i++;
		s += len;
	}
	split[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	split_len;

	split_len = ft_splitlen(s, c);
	if (split_len == 0)
		return (ft_calloc(1, sizeof(char *)));
	split = (char **)malloc((split_len + 1) * sizeof(char *));
	if (!split)
	{
		return (NULL);
	}
	if (!ft_splitwrite(s, split, c))
	{
		return (NULL);
	}
	return (split);
}
