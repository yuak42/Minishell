#ifndef BUILTIN_H
#define BUILTIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "../libft/libft.h"
#include "data_structures.h"
#include "prompt.h"

/* HEADER EKLE REIS bir de libft de mailin yanlis onu düzelt sonu .tr ile bitcek */


int		ft_echo(char **av, t_env *ev, int fd);
int		ft_export(char **av, t_env *env, int fd);
int		ft_env(t_env *ev, int fd);
int		ft_pwd(void);
int		ft_cd(char **av, t_env *env);
int		ft_unset(char **av, t_env **env);
void	execute(t_node *nodes, t_shell *shell);
char	**env_to_arry(t_env *ev);
int		is_builtin(char **argv);
int		ft_env_size(t_env *lst);
void	free_str(char **env, int i);
int		nodes_len(t_node *nodes);
int		run_builtin(char **argv, t_shell *shell, int fd);
int		ft_printf_fd(int fd, const char *input, ...);
int		ft_exit_ft(char **av, t_shell *shell);

#endif