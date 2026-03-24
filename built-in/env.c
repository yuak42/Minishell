/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-24 00:11:37 by byaprak           #+#    #+#             */
/*   Updated: 2026-03-24 00:11:37 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_list	*create_env(char **env)
{
	t_list *head;
	t_list *new;
	t_list *front;

	front = NULL;
	new = NULL;
	head = ft_lstnew(*env);
	if (!head)
		return (NULL);
	env++;
	while(*env)
	{
		new = ft_lstnew(*env);
		if(!new)
		{
			ft_lstclear(&head, free);
			return (NULL);
		}
		front = ft_lstlast(head);
		ft_lstadd_front(&front, new);
		env++;
	}
	return (head);
}
