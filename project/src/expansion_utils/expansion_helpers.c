/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:10:58 by yuak              #+#    #+#             */
/*   Updated: 2026/05/16 11:12:14 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

char	*connect_str(char *before, char *to_add) // think NULL cases later
{
	char	*final;

	final = ft_strjoin(before, to_add);
	free(before);
	free(to_add);
	if (!final)
		return (NULL);
	return (final);
}
