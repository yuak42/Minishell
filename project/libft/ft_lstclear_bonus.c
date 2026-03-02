/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:07:56 by yuak              #+#    #+#             */
/*   Updated: 2025/06/28 13:33:20 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;

	temp = *lst;
	while (temp != NULL)
	{
		head = (*temp).next;
		ft_lstdelone(temp, del);
		temp = head;
	}
	*lst = NULL;
}
