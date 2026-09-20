/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:33:32 by byaprak           #+#    #+#             */
/*   Updated: 2025/06/29 23:50:38 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*var;

	var = (char *)malloc((ft_strlen(s) * sizeof(char)) + 1);
	if (!var)
		return (NULL);
	ft_memcpy(var, s, ft_strlen(s) + 1);
	return (var);
}
