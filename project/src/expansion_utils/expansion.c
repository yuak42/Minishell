#include "prompt.h"

static void	expand(char **str, size_t i, t_env *ev);

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