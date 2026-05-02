#ifndef BUILTIN_H

#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "data_structures.h"
#include "prompt.h"

int		ft_echo(char **av, t_env *ev);
int		ft_export(char **av, t_env *env);
int		ft_env(t_env *ev);
int		ft_pwd(void);
int		ft_cd(char **av, t_env *env);
int		ft_unset(char **av, t_env **env);
void	execute(t_node *nodes, t_shell *shell);
char	**env_to_arry(t_shell *shell);
int		is_builtin(t_node *nodes, t_shell *shell);

typedef struct s_pipe_list
{
	char	*argv;
	char	**envp;
	int		inp;
	int		out;
}	t_pipe;

void	ft_free(char **str);
char	*ft_path_access(char **envp, char *command);
int		ft_pipex(char **argv, char **envp, int argc);
int		ft_fdswap(int std_new, int std_old);
void	ft_run_process(char *path, char **argv, char **envp);
int		ft_of(char *s);
int		ft_cf(char *s);
int		ft_process(t_pipe plist, int (*pipefd)[2], int pc, int *pd);
void	ft_exit(char *path, char **cmd);
t_pipe	ft_struct(char *argv, char **envp, int inp, int out);
void	ft_pipeclose(int (*pipefd)[2], int pc);
int		ft_wait(int *array, int count);
void	ft_pip(int ac, int (*fd)[2]);
char	*ft_path(char *argv, char **envp, char **cmd);

#endif