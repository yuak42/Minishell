#ifndef BUILTIN_H

#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "data_structures.h"
#include "prompt.h"

int		ft_echo(char **av, t_env *ev);
int		ft_export(char **av, t_env *env);
void	ft_env(t_env *ev);
int		ft_pwd(void);
int		ft_cd(char **av, t_env *env);
int		ft_unset(char **av, t_env **env);
void	execute(t_node *nodes, t_shell *shell);


#endif