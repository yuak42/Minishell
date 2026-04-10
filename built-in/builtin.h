#ifndef BUILTIN_H

#include<unistd.h>
#include<stdio.h>
#include "../libft/libft.h"

int		ft_echo(char **av, t_list *ev);
int		ft_export(char **av, t_list *env);
int		ft_env(t_list *env);
int		ft_pwd(void);
int		ft_cd(char **av, t_list *env);
int		ft_unset(char **av, t_list **env);

#endif