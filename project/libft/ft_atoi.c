/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:54:03 by byaprak           #+#    #+#             */
/*   Updated: 2025/06/29 23:48:26 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_negative(const char *nptr)
{
	int	n;
	int	count;

	count = 0;
	n = 1;
	if (*nptr != '-' && *nptr != '+' && !(*nptr >= '0' && *nptr <= '9'))
		return (0);
	while (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			n = -1;
		count++;
		nptr++;
	}
	if (count > 1)
		return (0);
	return (n);
}

int	ft_atoi(const char *nptr)
{
	int	c;
	int	i;

	i = 1;
	c = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (!(*nptr >= '0' && *nptr <= '9') && *nptr != '-' && *nptr != '+')
		return (0);
	i = ft_negative(nptr);
	if (i == 0)
		return (0);
	while (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		c = c * 10 + (*nptr - '0');
		nptr++;
	}
	return (c * i);
}
