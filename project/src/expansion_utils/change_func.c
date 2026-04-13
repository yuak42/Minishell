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

static void	fill_empty(char **str, char *var_name, char *new_value);
static void	fill_question(char **str, char *num_str, char *new_value);

void	change_to_none(char **str, char *var_name)
{
	char	*new_value;

	new_value = (char *) ft_calloc(sizeof(char), ft_strlen(*str) - ft_strlen(var_name));
	// if (!new_value) // deal later
	// 	return ;
	fill_empty(str, var_name, new_value);
	free(*str);
	*str = new_value;
}


void	change_to_exit_status(char **str, int exit_status)
{
	char	*num_str;
	char	*new_value;

	num_str = ft_itoa(exit_status);
	// if (!num_str) to do later
	// 	return ;
	new_value = (char *) ft_calloc(sizeof(char), ft_strlen(*str) - 1 + ft_strlen(num_str));
	// if (!new_value) to do later
	// 	return ;
	fill_question(str, num_str, new_value);
	free(*str);
	*str = new_value;
	free(num_str);
}

static void	fill_empty(char **str, char *var_name, char *new_value)
{
	size_t	i;
	size_t	j;

	i = 0;
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
}

static void	fill_question(char **str, char *num_str, char *new_value)
{
	size_t	i;
	size_t	j;

	i = 0;
	while ((*str)[i] != '$')
	{
		new_value[i] = (*str)[i];
		i++;
	}
	j = i + 2;
	while (*num_str)
	{
		new_value[i] = *num_str;
		num_str++;
	}

	while ((*str)[j])
	{
		new_value[i] = (*str)[j];
		j++;
		i++;
	}
}