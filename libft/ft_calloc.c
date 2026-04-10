/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:22:39 by byaprak           #+#    #+#             */
/*   Updated: 2025/06/29 23:52:11 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*var;

	var = malloc(nmemb * size);
	if (!var)
	{
		return (NULL);
	}
	ft_bzero(var, nmemb * size);
	return (var);
}
