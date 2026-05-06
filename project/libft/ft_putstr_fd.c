/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:46:03 by byaprak           #+#    #+#             */
/*   Updated: 2025/06/23 21:00:00 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int check;

	i = 0;
	while (s[i])
	{
		check = ft_putchar_fd(s[i], fd);
		if (!check)
			return (0);
		i++;
	}
	return (1);
}
