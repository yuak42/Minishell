#include "prompt.h"

void	change_invalid_identifier(char **str)
{
	char	*new_value;
	size_t	i;
	size_t	j;

	new_value = (char *) ft_calloc(ft_strlen(*str) - 1, sizeof(char));
	// if (!new_value) TODO later
	// 	return ;
	i = 0;
	while ((*str)[i] != '$')
	{
		new_value[i] = (*str)[i];
		i++;
	}
	j = i + 2;
	while ((*str)[j])
	{
		new_value[i] = (*str)[j];
		i++;
		j++;
	}
	free(*str);
	*str = new_value;
}

void	change_to_none(char **str, char *var_name)
{
	char	*new_value;
	size_t	i;
	size_t	j;

	i = 0;
	new_value = (char *) ft_calloc(sizeof(char), ft_strlen(*str) - ft_strlen(var_name));
	// if (!new_value) // deal later
	// 	return ;
	while ((*str)[i] != '$')
	{
		new_value[i] = (*str)[i];
		i++;
	}
	j = i;
	i++;
	while (*var_name)
	{
		var_name++;
		i++;
	}
	while ((*str)[i])
	{
		new_value[j] = (*str)[i];
		j++;
		i++;
	}
	free(*str);
	*str = new_value;
}