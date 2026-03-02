/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:51:03 by yuak              #+#    #+#             */
/*   Updated: 2025/07/01 14:48:48 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n);
static char		*create_str(char *str, int n, size_t size);

char	*ft_itoa(int n)
{
	char		*str;
	size_t		size;

	if (n == 0)
		return (ft_strdup("0"));
	size = get_len(n);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str = create_str(str, n, size);
	return (str);
}

static size_t	get_len(int n)
{
	size_t		len;
	long int	temp;

	len = 0;
	temp = (long int) n;
	if (n < 0)
		len++;
	while (temp != 0)
	{
		len++;
		temp /= 10;
	}
	return (len);
}

static char	*create_str(char *str, int n, size_t size)
{
	long int	temp;
	size_t		i;

	i = 0;
	temp = (long int) n;
	if (n < 0)
	{
		str[0] = '-';
		temp *= -1;
	}
	while (temp != 0)
	{
		str[size - i - 1] = temp % 10 + '0';
		temp /= 10;
		i++;
	}
	str[size] = '\0';
	return (str);
}
