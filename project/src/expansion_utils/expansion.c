/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:54 by yuak              #+#    #+#             */
/*   Updated: 2026/05/16 12:45:59 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	remove_quotes(char **str);
static size_t	get_number_quotes(char *str);
static void	fill(char *final, char *str);

int	expansion(t_shell *shell)
{
	t_token	*tokens;
	t_token	*head;

	head = shell->tokens;
	tokens = shell->tokens;
	while (tokens)
	{
		if (expand(&tokens->value, shell))
			return (1);
		else
			tokens = tokens->next;
	}
	while (head)
	{
		if (remove_quotes(&head->value))
			return (1);
		else
			head = head->next;
	}
	return (0);
}

static int	remove_quotes(char **str)
{
	size_t	new_len;
	char	*final;

	new_len = ft_strlen(*str) - get_number_quotes(*str);
	final = (char *) ft_calloc(new_len + 1, sizeof(char));
	if (!final)
		return (1);
	fill(final, *str);
	free(*str);
	*str = final;
	return (0);
}

static size_t	get_number_quotes(char *str)
{
	size_t	i;
	size_t	quote_num;

	i = 0;
	quote_num = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			while (str[i] != '\'')
				i++;
			quote_num = quote_num + 2;
		}
		else if (str[i] == '"')
		{
			while (str[i] != '"')
				i++;
			quote_num = quote_num + 2;
		}
		i++;
	}
	return (quote_num);
}

static void	fill(char *final, char *str)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'')
			{
				final[j] = str[i];
				i++;
				j++;
			}
			i++;
		}
		else if (str[i] == '"')
		{
			i++;
			while (str[i] != '"')
			{
				final[j] = str[i];
				i++;
				j++;
			}
			i++;
		}
		else
		{
			final[j] = str[i];
			j++;
			i++;
		}
	}
}