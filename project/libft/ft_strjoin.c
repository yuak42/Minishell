/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:48:00 by yuak              #+#    #+#             */
/*   Updated: 2025/07/01 14:42:31 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*all;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	all = (char *) malloc(i * sizeof(char));
	if (!all)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		all[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		all[i] = s2[j];
		i++;
		j++;
	}
	all[i] = '\0';
	return (all);
}
