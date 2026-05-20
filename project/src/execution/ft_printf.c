/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:20:54 by byaprak           #+#    #+#             */
/*   Updated: 2025/07/14 17:01:44 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	ft_print(int fd, char flag, va_list *args)
{
	int		len;

	if (flag == 'c')
		len = ft_putchar_fd((char)va_arg(*args, int), fd);
	if (flag == 's')
		len = ft_putstr_fd(va_arg(*args, char *), fd);
	return (len);
}

static int	ft_flag(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	ft_printf_fd(int fd, const char *input, ...)
{
	int		len;
	va_list	args;
	int		i;

	len = 0;
	i = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%' && ft_flag(input[i + 1]))
		{
			i++;
			len = ft_print(fd, input[i], &args);
		}
		else if (input[i] == '%' && input[i + 1] == '%')
		{
			len = ft_putchar_fd('%', fd);
			i++;
		}
		else
			len = ft_putchar_fd(input[i], fd);
		i++;
	}
	va_end(args);
	return (len);
}
