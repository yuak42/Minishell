/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:54 by yuak              #+#    #+#             */
/*   Updated: 2026/05/18 18:57:05 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

int	expansion(t_shell *shell)
{
	t_token	*tokens;
	t_token	*head;

	head = shell->tokens;
	tokens = shell->tokens;
	// print_tokens(head);
	while (tokens)
	{
		if (expand(&tokens->value, shell))
			return (1);
		else
			tokens = tokens->next;
	}
	// print_tokens(head);
	tokens = head;
	while (tokens)
	{
		if (remove_quotes(&tokens->value, tokens, &head))
			return (1);
		else
			tokens = tokens->next;
	}
	printf("----after quotes removed ----\n");
	print_tokens(head);
	shell->tokens = head;
	return (0);
}
