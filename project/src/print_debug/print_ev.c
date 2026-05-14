#include "prompt.h"

void	print_ev(t_env *ev)
{
	while (ev)
	{
		printf("%s=%s\n", ev->key, ev->value);
		ev = ev->next;
	}
}