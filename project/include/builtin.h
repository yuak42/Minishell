#ifndef BUILTIN_H

#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "data_structures.h"

void	ft_echo(char **av, t_env *ev);
void	ft_export(char **av, t_list *env);
void	ft_env(t_env *ev);
void	ft_pwd(void);
int		ft_cd(char **av, t_list *env);
int		ft_unset(char **av, t_list **env);

#endif