#include "prompt.h"

// static void print_env(t_env *ev);

int	main(int ac, char **av, char **env)
{
	t_env	*ev;
	(void) ac;
	(void) av;
	ev = get_env_list(env);
	//print_env(ev);
	basic_prompt(ev);
	(void) ev;
	(void) env;
	return 0;
}

// static void print_env(t_env *ev)
// {
// 	while (ev != NULL)
// 	{
// 		printf("%s=%s\n", ev->key, ev->value);
// 		ev = ev->next;
// 	}
// }
