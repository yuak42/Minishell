/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:02:27 by byaprak           #+#    #+#             */
/*   Updated: 2025/06/29 23:51:24 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	first;
	int	last;
	int	len;

	first = 0;
	len = ft_strlen(s1);
	last = len;
	while (ft_strchr(set, s1[first]))
		first++;
	while (ft_strrchr(set, s1[last]))
		last--;
	return (ft_substr(s1, first, (last - first) + 1));
}
