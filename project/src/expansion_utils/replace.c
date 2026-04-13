#include "prompt.h"

void	replace(char **str, char *var_name, t_env *ev)
{
	char *new_value;
	size_t	sbt;
	size_t	i;
	size_t	j;

	i = 0;
	sbt = ft_strlen(var_name);
	while (ev)
	{
		if (!(ft_strncmp(var_name, ev->key, sbt + 1)))
		{
			new_value = (char *) ft_calloc((ft_strlen(*str) - sbt + ft_strlen(ev->value) + 1), sizeof(char));
			// if (!new_value) TODO later
			// 	return ;
			while ((*str)[i] != '$')
			{
				new_value[i] = (*str)[i];
				i++;
			}
			j = i;
			while (ev->value[i])
			{
				new_value[i] = ev->value[i];
				i++;
			}
			j++;
			while (*var_name)
			{
				j++;
				var_name++;
			}
			while ((*str)[j])
			{
				new_value[i] = (*str)[j];
				j++;
				i++;
			}
			free(*str);
			*str = new_value;
			return ;
		}
		ev = ev->next;
	}
	// expansion bulunamadı ne yapılacak
	change_to_none(str, var_name);
}
