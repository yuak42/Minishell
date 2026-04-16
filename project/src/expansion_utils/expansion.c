#include "prompt.h"

static void	expand(char **str, size_t i, t_shell *shell);

int	expansion(t_token *tokens, t_shell *shell)
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
			{
				expand(&tokens->value, i, shell);
				if (!tokens->value)
					return (1);
			}

		}
	}
	return (0);
}

static void	expand(char **str, size_t i, t_shell *shell)
{
	size_t	j;
	char	*var_name;

	i++;
	if ((*str)[i] == '?')
		change_to_exit_status(str, shell->exit_status);
	else if (!(ft_isalpha((*str)[i]) || (*str)[i] == '_'))
		change_invalid_identifier(str);
	else
	{
		j = i;
		while (ft_isalpha((*str)[i]) || ft_isdigit((*str)[i]) || (*str)[i] == '_')
			i++;
		var_name = ft_substr(*str, j, i - j);
		if (!var_name)
		{
			free(*str);
			*str = NULL;
			return ;
		}
		replace(str, var_name, shell->ev);
		free(var_name);
	}
}