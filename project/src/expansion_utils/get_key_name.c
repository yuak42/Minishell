/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:32:48 by yuak              #+#    #+#             */
/*   Updated: 2026/05/16 14:31:22 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static char	*get_question_mark(size_t *i);
static char	*empty_string(size_t *i);
static char	*get_var_name(char *value, size_t start, size_t *i);

char	*get_key_name(char *str, size_t *i)
{
	size_t	start;
	char	*key;

	(*i)++;
	start = *i;
	if (str[*i] == '?')
		key = get_question_mark(i);
	else if (!is_start_varchar(str[*i]))
		key = empty_string(i);
	else
		key = get_var_name(str, start, i);
	return (key);
}

static char	*get_question_mark(size_t *i)
{
	char	*key;

	(*i)++;
	key = ft_strdup("?");
	if (!key)
		return (print_error("Error! ft_strdup\n"), NULL);
	return (key);
}

static char	*empty_string(size_t *i)
{
	char	*key;

	(*i)++;
	key = ft_strdup("");
	if (!key)
		return (print_error("Error! ft_strdup\n"), NULL);
	return (key);
}

static char	*get_var_name(char *str, size_t start, size_t *i)
{
	char	*key;

	(*i)++;
	while (is_varchar(str[*i]))
		(*i)++;
	key = ft_substr(str, start, *i - start);
	if (!key)
		return (print_error("Error! ft_substr\n"), NULL);
	return (key);
}
