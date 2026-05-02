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