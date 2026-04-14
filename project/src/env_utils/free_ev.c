#include "prompt.h"

void	free_ev(t_env *ev)
{
	t_env	*tmp;
	while (ev)
	{
		tmp = ev;
		free(ev->key);
		free(ev->value);
		ev = ev->next;
		free(tmp);
	}
}