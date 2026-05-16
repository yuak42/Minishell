/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 14:08:40 by yuak              #+#    #+#             */
/*   Updated: 2026/05/16 14:31:49 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static void		fill(char *final, char *str);
static void		handle_quotes(char *str, char *final, size_t *i, size_t *j);
static size_t	get_number_quotes(char *str);

int	remove_quotes(char **str)
{
	size_t	new_len;
	char	*final;

	if (*str == NULL)
		return (0);
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
			i++;
			while (str[i] != '\'')
				i++;
			quote_num = quote_num + 2;
		}
		else if (str[i] == '"')
		{
			i++;
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
		if (str[i] == '\'' || str[i] == '"')
			handle_quotes(str, final, &i, &j);
		else
		{
			final[j] = str[i];
			j++;
			i++;
		}
	}
}

static void	handle_quotes(char *str, char *final, size_t *i, size_t *j)
{
	if (str[*i] == '\'')
	{
		(*i)++;
		while (str[*i] != '\'')
		{
			final[*j] = str[*i];
			(*i)++;
			(*j)++;
		}
		(*i)++;
	}
	else
	{
		(*i)++;
		while (str[*i] != '"')
		{
			final[*j] = str[*i];
			(*i)++;
			(*j)++;
		}
		(*i)++;
	}
}
