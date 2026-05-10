/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:33 by yuak              #+#    #+#             */
/*   Updated: 2026/05/10 11:53:34 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	print_nodes(t_node *nodes)
{
	char	**argv;
	int		i = 0;

	// printf("print_nodes start\n");
	while (nodes)
	{
		argv = nodes->argv;
		printf("-------------------\nnode %d\n", i);
		printf("argv = [");
		if (argv == NULL)
			printf("NULL");
		else
		{
			while (*argv)
			{
				printf("\"%s\", ", *argv); // later to be make better
				argv++;
			}
			printf("NULL");
		}
		printf("]\n");

		if (!nodes->infile)
			printf("infile = NULL\n");
		else
			printf("infile = %s\n", nodes->infile);

		if (!nodes->outfile)
			printf("outfile = NULL\n");
		else
			printf("outfile = %s\n", nodes->outfile);

		printf("append = %d\n", nodes->append);
		printf("heredoc = %d\n", nodes->heredoc);
		printf("pipe_in = %d\n", nodes->pipe_in);
		printf("pipe_out = %d\n", nodes->pipe_out);

		printf("node %d\n-------------------\n", i);
		i++;
		nodes = nodes->next;
	}
	// printf("print_nodes end\n");
}