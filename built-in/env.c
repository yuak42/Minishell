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

	new = NULL;
	head = ft_lstnew(ft_strdup(*env));
	if (!head)
		return (NULL);
	env++;
	while(*env)
	{
		new = ft_lstnew(ft_strdup(*env));
		if(!new)
		{
			ft_lstclear(&head, free);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		env++;
	}
	return (head);
}

// int main(int ac, char **av, char **ev)
// {
// 	t_list *env = NULL;

// 	(void *)av;
// 	(void *)ev;
// 	env = create_env(ev);
// 	while (env)
// 	{
// 		printf("%s\n", (char *)env->content);
// 		env = env->next;
// 	}

// }
