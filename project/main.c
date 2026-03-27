#include "prompt.h"

int	main(int ac, char **av, char **env)
{
	// while (*env)
	// {
	// 	printf("%s\n", *env);
	// 	env++;
	// }
	(void) ac;
	(void) av;
	basic_prompt(env);
	return 0;
}
