/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-01 21:34:09 by byaprak           #+#    #+#             */
/*   Updated: 2026-04-01 21:34:09 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static t_list	*is_target(t_list *env, char *av)
{
	char	*str;

	while (env)
	{
		str = ft_strnstr(env->content, av, ft_strlen(av));
		if (str && (*(str + ft_strlen(av)) == '=' || *(str + ft_strlen(av)) == '\0'))
			return (env);
		env = env->next;
	}
	return (NULL);
}

static void	break_node(t_list **head, t_list **node)
{
	t_list	*back;
	t_list	*next;

	back = (*node)->back;
	next = (*node)->next;
	(*node)->back = NULL;
	(*node)->next = NULL;
	if (back)
		back->next = next;
	else
		*head = next;
	if (next)
		next->back = back;
}

int	ft_unset(char **av, t_list **env)
{
	t_list	*node;

	av++;
	if (!*av)
		return(0);
	while (*av)
	{
		node = is_target(*env, *av);
		if (node)
		{
			break_node(env, &node);
			ft_lstdelone(node, free);
		}
		av++;
	}
	return (0);

}

// unset 1=gdtt gibi bir durumda hata yzdıracak mı?
// uset new durumunu kontrol et
