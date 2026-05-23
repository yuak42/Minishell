/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 22:32:41 by byaprak           #+#    #+#             */
/*   Updated: 2026/05/23 14:04:01 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

int	ft_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (!path)
	{
		perror("");
		return (1);
	}
	if (printf("%s\n", path) < 0)
	{
		perror("");
		free(path);
		return (1);
	}
	free(path);
	return (0);
}
