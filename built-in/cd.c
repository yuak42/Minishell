/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-31 15:10:04 by byaprak           #+#    #+#             */
/*   Updated: 2026-03-31 15:10:04 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static t_list	*is_home(t_list *env)
{
	while (env)
	{
		if (ft_strnstr(env->content, "HOME=", 5))
			return (env);
		env = env->next;
	}
	return (NULL);
}

int	ft_cd(char **av, t_list *env)
{
	int		ex;
	t_list	*node;
	char	*path;

	node = NULL;
	av++;
	if (!*av)
	{
		node = is_home(env);
		if (node)
		{
			path = node->content +5;
			ex = chdir(path);
		}
		else
			ex = -1;
	}
	else
		ex = chdir(*av);
	if (ex == -1)
	{
		perror("");
		return (1);
	}
	return(0);
}

