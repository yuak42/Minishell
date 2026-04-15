#include "prompt.h"

void	print_nodes(t_node *nodes)
{
	char	**argv;

	printf("print_nodes start\n");
	while (nodes)
	{
		argv = nodes->argv;
		printf("[");
		while (*argv)
		{
			printf("%s ", *argv);
			argv++;
		}
		printf("]\n");
		nodes = nodes->next;
	}
	printf("print_nodes end\n");
}