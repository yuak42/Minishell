/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:52:43 by byaprak           #+#    #+#             */
/*   Updated: 2025/07/03 15:29:38 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_listcopy(t_list *lst, void (*del)(void *),
	void *(*f)(void *))
{
	t_list	*list;
	t_list	*new;
	void	*content;

	list = NULL;
	new = NULL;
	while (lst)
	{
		content = f(lst->content);
		new = (ft_lstnew(content));
		if (!new)
		{
			del(content);
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, new);
		lst = lst-> next;
	}
	return (list);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;

	if (!lst || !f || !del)
		return (NULL);
	list = ft_listcopy(lst, del, f);
	return (list);
}
