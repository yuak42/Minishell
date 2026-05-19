/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:38:31 by byaprak           #+#    #+#             */
/*   Updated: 2025/09/28 19:48:07 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "prompt.h"
#include  <sys/stat.h>

typedef struct s_pipe_list
{
	char	**argv;
	t_env	**envp;
	int		inp;
	int		out;
	int		(*pipefd)[2];
	t_shell *shell;
	t_node	*node;
}	t_pipe;

void	ft_free(char **str);
char	*ft_path_access(char *command, char *path_dir);
int		ft_pipex(t_node *node, t_shell *shell, int ac);
int		ft_fdswap(int std_new, int std_old);
void	ft_run_process(t_pipe plist);
int		ft_of(char *s);
int		ft_cf(char *s);
int		ft_process(t_pipe plist, int (*pipefd)[2], int pc, int *pd);
//void	ft_exit(char *path, char **cmd);
t_pipe	ft_struct(t_node *node, t_shell *shell, int (*fd)[2], int i);
void	ft_pipeclose(int (*pipefd)[2], int pc);
int		ft_wait(int *array, int count);
void	ft_pip(int ac, int (*fd)[2]);
char	*ft_path(char **argv, char **envp, struct stat *statbuf);
int		ft_af(char *s);
void	ft_all_free(t_pipe plist);
char	*path_check(t_pipe plist, char **ev);
int		ft_redir(t_node *nodes);//, t_shell *shell);

#endif