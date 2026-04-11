#include "prompt.h"

int	main(int ac, char **av, char **env)
{
	t_env	*ev;
	(void) ac;
	(void) av;
	ev = get_env_list(env);
	basic_prompt(ev);
	return 0;
}
