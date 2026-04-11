#include "prompt.h"

void	execute(t_node *node, t_env *ev)
{
	if (!ft_strncmp("env", node->args[0], 4))
		ft_env(ev);
	else if (!ft_strncmp("pwd", node->args[0], 4))
		ft_pwd();
	else if (!ft_strncmp("echo", node->args[0], 5))
		ft_echo(node->args + 1, ev);
	else
		printf("%s: command not found!\n", node->args[0]);

}