/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:54 by yuak              #+#    #+#             */
/*   Updated: 2026/05/13 20:23:27 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	expand(char **value, t_shell *shell);
int	get_state(char c, int quote);
char	*connect_str(char *value, char *conn);
char	*connect_expansion(char *final, char *value, size_t i, t_shell *shell);
char	*get_env_value_dup(t_shell *shell, char *key);

int	expansion(t_shell *shell)
{
	t_token	*tokens;

	tokens = shell->tokens;
	while (tokens)
	{
		if (expand(&tokens->value, shell))
			return (1);
		else
			tokens = tokens->next;
	}
	// remove quotes
	return (0);
}

static int	expand(char **value, t_shell *shell)
{
	size_t	i;
	int		quote;
	size_t	start;
	char	*final;

	i = 0;
	quote = 0;
	start = 0;
	while ((*value)[i])
	{
		quote = get_state((*value)[i], quote);	
		if ((*value)[i] == '$' && quote == 0)
		{
			printf("it was here\n");
			final = connect_str(*value, ft_substr(*value, start, i - start));
			if (!final)
				return (1);
			final = connect_expansion(final, *value, i, shell);
			if (!final)	
				return (1);
			start = i;
		}
		i++;
	}
	free(*value);
	*value = final;
	return (0);
}

int	get_state(char c, int quote)
{
	if (c == '\'' && quote == 0)
		return (1);
	if (c == '\'' && quote == 1)
		return (0);
	if (c == '"' && quote == 0)
		return (2);
	if (c == '"' && quote == 2)
		return (0);
	return (0);
}

char	*connect_str(char *value, char *conn)
{
	char	*final;

	if (!conn)
		return (NULL);
	final = ft_strjoin(value, conn);
	if (!final)
		return (NULL);
	// free(conn);
	final = value;
	return (final);
}

char	*connect_expansion(char *final, char *value, size_t i, t_shell *shell)
{
	char	*key;
	char	*temp;
	size_t	j;
	
	j = i + 1;
	while (value[j] && (value[j] != ' ' || value[j] != '\t'))
		j++;
	key = ft_substr(value, i + 1, j - i - 1);
	if (!key)
		return (NULL);
	temp = connect_str(final, get_env_value_dup(shell, key));
	if (!temp)
		return (NULL);
	// free(final);
	return (temp);
}

char	*get_env_value_dup(t_shell *shell, char *key)
{
	char	*value;
	char	*s;

	value = get_env_value(shell->ev, key);
	s = ft_strdup(value);
	if (!s)
		return (NULL);
	return (s);
}

//FIX NORM HEADER MAIL IS WRONG