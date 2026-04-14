#include "prompt.h"

void	execute(t_node *node, t_env *ev)
{
	if (!ft_strncmp("env", node->args[0], 4))
		ft_env(ev);
	else if (!ft_strncmp("pwd", node->args[0], 4))
		ft_pwd();
	else if (!ft_strncmp("echo", node->args[0], 5))
		ft_echo(node->args, ev);
	else if (!ft_strncmp("cd", node->args[0], 3))
		ft_cd(node->args, ev);
	else if (!ft_strncmp("export", node->args[0], 7))
		ft_export(node->args, ev);
	else
		printf("%s: command not found!\n", node->args[0]);

}
