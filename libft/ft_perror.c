/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-04 16:06:57 by byaprak           #+#    #+#             */
/*   Updated: 2026-04-04 16:06:57 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putchar(char c)
{
	write(2, &c, 1);
	return (1);
}

static int	ft_putstr(char *s)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (!s)
	{
		len += ft_putstr("(null)");
		return (len);
	}
	while (s[i])
	{
		len += ft_putchar(s[i]);
		i++;
	}
	return (len);
}

int	ft_perror(const char *input, char *value)
{
	int		len;

	len = 0;
	while (*input)
	{
		if (*input == '%' && *(input + 1) == 's')
		{
			input++;
			len += ft_putstr(value);
		}
		else
			len += ft_putchar(*input);
		input++;
	}
	return (len);
}
