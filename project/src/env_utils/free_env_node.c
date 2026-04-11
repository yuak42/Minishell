#include "prompt.h"

void	free_env_node(t_env *node)
{
	free(node->key);
	free(node->value);
	free(node);
}