/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:53:54 by yuak              #+#    #+#             */
/*   Updated: 2026/05/16 20:06:30 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

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
	// print_tokens(head);
	tokens = head;
	while (head)
	{
		if (remove_quotes(&head->value))
			return (1);
		else
			head = head->next;
	}
	// printf("----after quotes removed ----\n");
	// print_tokens(tokens);
	return (0);
}
