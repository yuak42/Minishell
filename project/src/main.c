#include "prompt.h"

int	main(int ac, char **av, char **env)
{
	t_shell	*shell;
	(void) ac;
	(void) av;
	shell = (t_shell *) malloc(sizeof(t_shell));
	if (!shell)
		return (1);
	shell->ev = get_env_list(env);
	shell->exit_status = 0;
	basic_prompt(shell);
	return 0;
}
