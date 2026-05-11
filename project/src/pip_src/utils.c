/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:38:47 by byaprak           #+#    #+#             */
/*   Updated: 2025/09/28 20:09:26 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_of(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	return (fd);
}

int	ft_cf(char *s)
{
	int	fd;

	fd = open(s, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (fd);
}

int	ft_fdswap(int std_new, int std_old)
{
	if (std_new == -1)
	{
		perror("-minishell:");
		return (0);
	}
	if (dup2(std_new, std_old) == -1)
	{
		perror("-minishell:");
		return (0);
	}
	return (1);
}

void	ft_run_process(t_pipe plist)
{
	//int		status;
	char	**ev;
	char	*path;
// node-> argv içinde mallocla açılmış mı 
	//status = 1;
	ev = env_to_arry(*plist.envp);// hata kontrolü ekle
	path = ft_path(plist.argv, ev);
	if (!path)
	{
		ft_printf_fd(2,"bash: %s: command not found\n", plist.argv[0]);
		free_str(ev, -1);
		ft_free(plist.argv);
		exit(127);
	}
	// if (is_builtin(plist.argv))
	// {
	// 	printf("-------------BUİLTİN------------------------------\n");
	// 	status = run_builtin(plist.argv, plist.shell, 1);
	// 	free(path);
	// 	free(plist.argv);
	// 	free_ev(*plist.envp);
	// 	free_str(ev, - 1);
	// 	exit(status);
	// }
	if (execve(path, plist.argv, ev) == -1)
	{
		//printf("-------------PROCESSSSSSSSSSS-----------------\n");
		free(path);
		ft_free(plist.argv);
		free_ev(*plist.envp);
		free_str(ev, -1);
		exit(EXIT_FAILURE);
	}
}

t_pipe	ft_struct(t_node *node, t_shell *shell, int (*fd)[2], int i)
{
	t_pipe	p_list;

	p_list.node = node;
	p_list.shell = shell;
	p_list.argv = node->argv;
	p_list.envp = &shell->ev;
    p_list.inp = STDIN_FILENO;
    p_list.out = STDOUT_FILENO;
	if (node->infile)
		p_list.inp = ft_of(node->infile);
	else if (node->pipe_in)
		p_list.inp = fd[i - 1][0];
	if (node->outfile && !node->append)
		p_list.out = ft_cf(node->outfile);
	else if (node->outfile && node->append)
		p_list.out = ft_af(node->outfile);
	else if (node->pipe_out)
		p_list.out = fd[i][1];
	return (p_list);
}
