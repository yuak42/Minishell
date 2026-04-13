#include "prompt.h"

static void	replace_value(char **str, char *value, size_t new_len);
static void	fill(char **str, char *value,  char *new_value);

void	replace(char **str, char *var_name, t_env *ev)
{
	size_t	len;
	
	len = ft_strlen(*str) - ft_strlen(var_name) + ft_strlen(ev->value) + 1;
	while (ev)
	{
		if (!(ft_strncmp(var_name, ev->key, ft_strlen(var_name) + 1)))
		{
			replace_value(str, ev->value, len);
			return ; // NULL mu diye disarda kontrol
		}
		ev = ev->next;
	}
	// expansion bulunamadı ne yapılacak
	change_to_none(str, var_name);
}

static void	replace_value(char **str, char *value, size_t new_len)
{
	char	*new_value;

	new_value = (char *) ft_calloc(new_len, sizeof(char));
	if (!new_value)
	{
		free(*str);
		*str = NULL;
		return ;
	}
	fill(str, value, new_value);
	free(*str);
	*str = new_value;
}

static void	fill(char **str, char *value, char *new_value)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((*str)[i] != '$')
	{
		new_value[i] = (*str)[i];
		i++;
	}
	j = i;
	while (value[i])
	{
		new_value[i] = value[i];
		i++;
	}
	j++;
	while ((*str)[j])
	{
		new_value[i] = (*str)[j];
		j++;
		i++;
	}
}