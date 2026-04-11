#ifndef BUILTIN_H

#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "data_structures.h"

int		ft_echo(char **av, t_env *ev);
int		ft_export(char **av, t_env *env);
void	ft_env(t_env *ev);
int		ft_pwd(void);
int		ft_cd(char **av, t_env *env);
int		ft_unset(char **av, t_list **env);
char	*get_env_value(t_env *ev, char *key);
void	set_env_value(t_env *ev, char *key, char *value);

#endif