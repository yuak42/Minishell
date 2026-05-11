/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:54 by yuak              #+#    #+#             */
/*   Updated: 2026/05/11 18:08:42 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	expand(char **value, size_t *i, t_shell *shell);

int	expansion(t_shell *shell)
{
	int		state;
	size_t	i;
	t_token	*tokens;

	tokens = shell->tokens;
	while (tokens)
	{
		i = 0;
		if (tokens->value[i] == '\'')
			state = 1;
		else
			state = 0;
		while (tokens->value && tokens->value[i])
		{
			if (state == 0)
				expand(&tokens->value, &i, shell);
			if (state == 0 && tokens->value[i] == '\'')
				state = 1;
			else if (state == 1 && tokens->value[i] == '\'')
				state = 0;
			i++;
		}
		tokens = tokens->next;
	}
	return (0);
}

static int	expand(char **value, size_t *i, t_shell *shell)
{
	(void) value;
	(void) i;
	(void) shell;
	return (0);
}


// static void	expand(char **str, size_t i, t_shell *shell)
// {
// 	size_t	j;
// 	char	*var_name;

// 	i++;
// 	if ((*str)[i] == '?')
// 		change_to_exit_status(str, shell->exit_status);
// 	else if (!(ft_isalpha((*str)[i]) || (*str)[i] == '_'))
// 		change_invalid_identifier(str);
// 	else
// 	{
// 		j = i;
// 		while (ft_isalpha((*str)[i]) || ft_isdigit((*str)[i]) || (*str)[i] == '_')
// 			i++;
// 		var_name = ft_substr(*str, j, i - j);
// 		if (!var_name)
// 		{
// 			free(*str);
// 			*str = NULL;
// 			return ;
// 		}
// 		replace(str, var_name, shell->ev);
// 		free(var_name);
// 	}
// }
