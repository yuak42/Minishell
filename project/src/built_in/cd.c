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
		ft_perror("bash: cd: %s not set\n", "HOME"); // Niye boyle ??? normal perror boyle degil???
	}
	return (ex);
}

static void pwd_update(t_env *env)
{
	char	*new_pwd;

	new_pwd = getcwd(NULL, 0); // dinamik zaten
	if (!env || !new_pwd)
		return ;
	set_env_value(env, "PWD", new_pwd);
}

static void old_pwd_update(t_env *env, char *here)
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
	pwd_update(env);
	old_pwd_update(env, here);
	free(here);
	return (0);
}
//env'de pwd ve old pwd update et.

/* yuak notes

1. Eğer CDPATH diye bir çevre değişken set edilmişse önce gideceği klasörü orada arıyor. -> buna evo page'de var mı bakalım

Örnek olarak
1.1 home klasöründeyken deneme diye bir klasör aç
1.2 sonra Desktop içinde bir tane daha deneme klasörü aç
1.3 home klasöründe olduğundan emin ol.
1.4 "export CDPATH=Desktop" çalıştır.
1.5 şimdi "cd deneme" çalıştır
1.6 nereye gittiğini gözlemle, normalde direkt /home/deneme klasörüne gidecektin ama CDPATH ataması yaptığımız
	için /home/Desktop/deneme yoluna gittin.

2. "cd -" komutu $OLDPWD değişkenine götürecek


3. If cd uses a non-empty directory name from CDPATH, or if ‘-’ is the first argu-
ment, and the directory change is successful, cd writes the absolute pathname
of the new working directory to the standard output.
---->> Yani cd CDPATH kullanarak gittiyse veya - kullanarak gittiyse gittiği yerin
tam adresini yazmalı
örnek olarak "cd -" yazıp dene

*/
