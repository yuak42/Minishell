/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:10:58 by yuak              #+#    #+#             */
/*   Updated: 2026/05/15 19:20:22 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*connect_str(char *before, char *to_add)
{
	char	*final;

	if (!before)
		return (to_add);
	if (!to_add)
		return (before);
	final = ft_strjoin(before, to_add);
	if (!final)
		return (NULL);
	free(before);
	free(to_add);
	return (NULL);
}
