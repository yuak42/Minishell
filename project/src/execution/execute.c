#include "prompt.h"



void	execute(t_node *nodes, t_shell *shell)
{
	int status;
	if (!nodes->next && is_builtin(nodes->argv))
	{
		status = run_builtin(nodes->argv, &shell->ev);
		printf("-------%d--------\n", status);
		if (status)
			return ;
	}
	else
		status = ft_pipex(nodes, &shell->ev, nodes_len(nodes));
	shell->exit_status = status;
	//printf("execution ...\n");
}
