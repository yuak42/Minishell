/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:33 by yuak              #+#    #+#             */
/*   Updated: 2026/05/17 10:12:50 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	print_int_arr(int *arr);
void	print_char_arr(char **arr);

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
		{
			printf("infile = ");
			print_char_arr(nodes->infile);
		}

		if (!nodes->outfile)
			printf("outfile = NULL\n");
		else
		{
			printf("outfile = ");
			print_char_arr(nodes->outfile);
		}

		if (!nodes->append)
			printf("append = NULL\n");
		else
		{
			printf("append = ");
			print_int_arr(nodes->append);
		}
		if (!nodes->heredoc)
			printf("heredoc = NULL\n");
		else
		{
			printf("heredoc = ");
			print_int_arr(nodes->heredoc);
		}
		printf("pipe_in = %d\n", nodes->pipe_in);
		printf("pipe_out = %d\n", nodes->pipe_out);

		i++;
		nodes = nodes->next;
	}
	printf("\n------- OUTPUT -------\n");
}

void	print_char_arr(char **arr)
{
	while (*arr)
	{
		printf("\"%s\" ", *arr);
		arr++;
	}
	printf("\n");
}

void	print_int_arr(int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != -1)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}