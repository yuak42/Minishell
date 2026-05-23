/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:38:31 by byaprak           #+#    #+#             */
/*   Updated: 2026/05/23 14:08:34 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "data_structures.h"
# include <sys/stat.h>

void	ft_free(char **str);
char	*ft_path_access(char *command, char *path_dir);
int		ft_pipex(t_node *node, t_shell *shell, int ac);
int		ft_fdswap(int std_new, int std_old);
void	ft_run_process(t_pipe plist);
int		ft_of(char *s);
int		ft_cf(char *s);
int		ft_process(t_pipe plist, int (*pipefd)[2], int pc, int *pd);
t_pipe	ft_struct(t_node *node, t_shell *shell, int (*fd)[2], int i);
void	ft_pipeclose(int (*pipefd)[2], int pc);
int		ft_wait(int *array, int count);
void	ft_pip(int ac, int (*fd)[2]);
char	*ft_path(char **argv, char **envp, struct stat *statbuf, int *status);
int		ft_af(char *s);
void	ft_all_free(t_pipe plist);
char	*path_check(t_pipe plist, char **ev);
int		ft_redir(t_node *nodes);

#endif