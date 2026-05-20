/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:52:52 by yuak              #+#    #+#             */
/*   Updated: 2026/05/20 18:04:35 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static char	**get_argv_increased(char **argv);

void	add_arg(char ***argv, char *arg)
{
	char	**temp;
	size_t	i;
	char	**new_argv;

	i = 0;
	new_argv = get_argv_increased(*argv);
	if (!new_argv)
	{
		free(*argv);
		*argv = NULL;
		return ;
	}
	temp = *argv;
	while (temp != NULL && temp[i])
	{
		new_argv[i] = temp[i];
		i++;
	}
	new_argv[i] = arg;
	new_argv[i + 1] = NULL;
	free(*argv);
	*argv = new_argv;
}

static char	**get_argv_increased(char **argv)
{
	char	**temp;
	char	**new_argv;
	size_t	len;

	temp = argv;
	len = 0;
	while (temp != NULL && *temp)
	{
		len++;
		temp++;
	}
	new_argv = (char **) ft_calloc(len + 2, sizeof(char *));
	if (!new_argv)
		return (NULL);
	return (new_argv);
}
