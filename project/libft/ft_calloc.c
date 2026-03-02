/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:33:52 by yuak              #+#    #+#             */
/*   Updated: 2025/07/03 13:08:40 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			limit;
	unsigned char	*temp;

	limit = (size_t) -1;
	if (size != 0 && nmemb > limit / size)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	temp = malloc(nmemb * size);
	if (!temp)
		return (NULL);
	ft_memset(temp, 0, nmemb * size);
	return (temp);
}
