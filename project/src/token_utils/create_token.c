/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 14:56:47 by yuak              #+#    #+#             */
/*   Updated: 2026/05/10 14:57:07 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

t_token	*create_token(char *str, size_t s, size_t i, char state)
{
	char	*value;
	t_token	*token;

	token = (t_token *) malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	value = ft_substr(str, s, i - s);
	if (!value)
		return (free(token), NULL); //free need
	token->value = value;
	if (state == ' ')
		token->state = state_normal;
	else if (state == '\'')
		token->state = state_quote_single;
	else if (state == '"')
		token->state = state_quote_double;
	decide_token_type(token, value);
	token->next = NULL;
	return (token);
}