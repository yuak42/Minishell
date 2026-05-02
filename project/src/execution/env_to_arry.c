/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_arry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-02 12:56:11 by byaprak           #+#    #+#             */
/*   Updated: 2026-05-02 12:56:11 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"prompt.h"

static void	free_str(char **env, int i)
{
	while(i >= 0)
	{
		free(env[i]);
		i--;
	}
	free(env);
}

static char	*str_append_str(t_env *ev)
{
	char	*join;
	char	*append;

	join = ft_strjoin(ev->key, "=");
	if (!join)
		return (NULL);
	if (!ev->value) // burayı sor ev-> valueye null yazıyor mu.
		append = ft_strjoin(join, "");
	else
		append = ft_strjoin(join, ev->value);
	if(!append)
	{
		free(join);
		return (NULL);
	}
	free(join);
	return(append);
}

char	**env_to_arry(t_shell *shell)
{
	char	**env;
	int		i;

	i = 0;
	env = ft_calloc(sizeof(char *), ft_env_size(shell->ev) + 1);
	if (!env)
		return (NULL);
	while (shell->ev)
	{
		env[i] = str_append_str(shell->ev);
		if (!env[i])
		{
			perror("-minishell");
			free_str(env, i);
			return (NULL);
		}
		shell->ev = shell->ev->next;
		i++;
	}
	env[i] = NULL;
	return (env);
}
