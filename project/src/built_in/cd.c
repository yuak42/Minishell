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

static int	get_home(t_env *env)
{
	int		ex;
	char	*value;

	value = get_env_value(env, "HOME");
	if (value)
		ex = chdir(value);
	else
	{
		ex = -2;
		ft_perror("bash: cd: %s not set\n", "HOME");
	}
	return (ex);
}

static void	pwd_update(t_env *env)
{
	char	*new_pwd;

	new_pwd = getcwd(NULL, 0);
	if (!env || !new_pwd)
		return ;
	set_env_value(env, "PWD", new_pwd);
}

static void	old_pwd_update(t_env *env, char *here)
{
	if (!env)
		return ;
	set_env_value(env, "OLDPWD", here);
}

int	ft_cd(char **av, t_env *env)
{
	int		ex;
	char	*here;

	av++;
	if (av[1])
	{
		ft_printf_fd(2, "-minishell: cd: too many arguments\n");
		return (1);
	}
	here = getcwd(NULL, 0);
	if (!here)
		return (1);
	if (!*av)
		ex = get_home(env);
	else if (!ft_strncmp(*av, "-", 2))
		ex = chdir(get_env_value(env, "OLDPWD"));
	else
		ex = chdir(*av);
	if (ex == -1 || ex == -2)
	{
		if (ex == -1)
			ft_perror("-minishell: cd: %s: No such file or directory\n", *av);
		return (free(here), 1);
	}
	return (pwd_update(env), old_pwd_update(env, here), 0);
}
