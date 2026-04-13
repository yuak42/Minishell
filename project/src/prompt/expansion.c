#include "prompt.h"

static void	replace(char **str, char *var_name, t_env *ev);
static void	expand(char **str, size_t i, t_env *ev);
static void	change_invalid_identifier(char **str);
static void	change_to_none(char **str, char *var_name);

void	expansion(t_token *tokens, t_env *ev)
{
	size_t	i;

	while (tokens)
	{
		if (tokens->state == state_quote_single)
			tokens = tokens->next;
		else
		{
			i = 0;
			while (tokens->value[i] && tokens->value[i] != '$')
				i++;
			if (tokens->value[i] == '\0')
				tokens = tokens->next;
			else
				expand(&tokens->value, i, ev);
		}
	}
}

static void	expand(char **str, size_t i, t_env *ev)
{
	size_t	j;
	char	*var_name;

	i++;
	if (!(ft_isalpha((*str)[i]) || (*str)[i] == '_'))
		change_invalid_identifier(str); // burada ? mi kontrol etmeliyiz sonra
	else
	{
		j = i;
		while (ft_isalpha((*str)[i]) || ft_isdigit((*str)[i]) || (*str)[i] == '_')
			i++;
		var_name = ft_substr(*str, j, i - j);
		replace(str, var_name, ev);
		free(var_name);
	}
}

static void	replace(char **str, char *var_name, t_env *ev)
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

static void	change_invalid_identifier(char **str)
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

static void	change_to_none(char **str, char *var_name)
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