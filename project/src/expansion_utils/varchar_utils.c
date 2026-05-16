/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varchar_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:10:36 by yuak              #+#    #+#             */
/*   Updated: 2026/05/16 14:30:56 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

int	is_varchar(char c)
{
	if (ft_isdigit(c) || ft_isalpha(c) || c == '_')
		return (1);
	return (0);
}

int	is_start_varchar(char c)
{
	if (ft_isalpha(c) || c == '_')
		return (1);
	return (0);
}
