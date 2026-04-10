/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 21:59:48 by byaprak           #+#    #+#             */
/*   Updated: 2025/06/29 23:49:11 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	count;
	int		j;

	count = 1;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	if (n == 0)
		return (count);
	j = n / 10;
	while (j > 0)
	{
		count++;
		j = j / 10;
	}
	return (count);
}

static int	ft_putnbr(int b, char *str, int i)
{
	if (b >= 10)
		i = ft_putnbr(b / 10, str, i);
	str[i] = (b % 10) + '0';
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*istr;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	len = ft_intlen(n);
	istr = malloc((len + 1) * sizeof(char));
	if (!istr)
		return (NULL);
	if (n < 0)
	{
		i = 0;
		n = -n;
		istr[i] = '-';
		i++;
	}
	i = ft_putnbr(n, istr, i);
	istr[i] = '\0';
	return (istr);
}
