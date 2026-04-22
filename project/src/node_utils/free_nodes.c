#include "prompt.h"

void	free_nodes(t_node *nodes)
{
	t_node	*temp;

	while (nodes)
	{
		temp = nodes;
		free(nodes->argv);
		nodes = nodes->next;
		free(temp);
	}
}