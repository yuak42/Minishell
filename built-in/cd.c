/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-31 15:10:04 by byaprak           #+#    #+#             */
/*   Updated: 2026-03-31 15:10:04 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

// static t_list	*is_home(t_list *env)
// {
// 	while (env)
// 	{
// 		if (ft_strnstr(env->content, "HOME=", 5))
// 			return (env);
// 		env = env->next;
// 	}
// 	return (NULL);
// }

static int	get_home(t_list *env)
{
	t_list	*node;
	int		ex;

	node = ft_getenv(env, "HOME");
	if (node)
	{
		ex = chdir(node->content + 5);
	}
	else
	{
		ex = -2;
		ft_perror("-minishell: cd: %s not set\n", "HOME");
	}
	return (ex);
}

static void pwd_update(t_list *env)
{
	char	*content;
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!env || !pwd)
		return ;
	content = ft_strjoin("PWD=", pwd);
	if (!content)
	{
		free(pwd);
		return ;
	}
	free(env->content);
	env->content = content;
	free(pwd);
}

static void old_pwd_update(t_list *env, char *here)
{
	char	*content;

	if (!env)
		return ;
	content = ft_strjoin("OLDPWD=", here);
	if (!content)
		return ;
	free(env->content);
	env->content = content;
}

int	ft_cd(char **av, t_list *env)
{
	int		ex;
	char	*here;

	av++;
	here = getcwd(NULL, 0);
	if (!here)
		return (1);
	if (!*av)
		ex = get_home(env);
	else
		ex = chdir(*av);
	if (ex == -1 || ex == -2)
	{
		if (ex == -1)
			ft_perror("minishell: cd: %s: No such file or directory\n", *av);
		free(here);
		return (1);
	}
	pwd_update(ft_getenv(env, "PWD"));
	old_pwd_update(ft_getenv(env, "OLDPWD"), here);
	free(here);
	return (0);
}
//env'de pwd ve old pwd update et.

