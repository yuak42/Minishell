#include "prompt.h"

void	execute(t_node *node, t_env *ev)
{
	printf("%s: command not found!\n", node->args[0]);
	(void) node;
	(void) ev;
}