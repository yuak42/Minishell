#include "prompt.h"



void	execute(t_node *nodes, t_shell *shell)
{
	int status;
	if (!nodes->next)
	{
		status = is_builtin(nodes->argv, shell->ev);
		if (status)
			return ;
	}
	//ft_pipex(nodes, shell->ev, nodes_len(nodes));
	printf("execution ...\n");
}
