/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:55:24 by yuak              #+#    #+#             */
/*   Updated: 2025/07/01 14:47:47 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			count_words(char const *s, char c);
static int			word_len(char const *s, char c);
static void			*free_all(char **arr, int words_allocated);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	arr = (char **) malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			arr[i] = ft_substr(s, 0, word_len(s, c));
			if (arr[i] == NULL)
				return (free_all(arr, i));
			s += word_len(s, c);
			i++;
		}
		else
			s++;
	}
	arr[i] = NULL;
	return (arr);
}

static int	count_words(char const *s, char c)
{
	int	word_num;

	word_num = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			word_num++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (word_num);
}

static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

static void	*free_all(char **arr, int words_allocated)
{
	int	i;

	i = 0;
	while (i < words_allocated)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}
