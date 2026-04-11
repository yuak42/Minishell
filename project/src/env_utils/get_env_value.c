#include "builtin.h"

char	*get_env_value(t_env *ev, char *key)
{
	while (ev)
	{
		if (!ft_strncmp(ev->key, key, ft_strlen(key) + 1))
			return (ev->value);
		ev = ev->next;
	}
	return (NULL);
}