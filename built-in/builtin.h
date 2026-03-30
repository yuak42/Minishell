#ifndef BUILTIN_H

#include<unistd.h>
#include<stdio.h>
#include "../libft/libft.h"

void	ft_echo(char **av, t_list *ev);
void	ft_export(char **av, t_list *env);
void	ft_env(t_list *env);
void	ft_pwd(void);


#endif