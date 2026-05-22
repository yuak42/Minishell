/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:49:03 by yuak              #+#    #+#             */
/*   Updated: 2026/05/22 21:07:45 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	is_operator_syntax_correct(t_token *tokens);
static int	is_quote_syntax_correct(t_token *tokens);
static int	is_syntax_correct(t_token *tokens);
static int	is_token_quote_correct(char *value);

int	tokenizer(char *line, t_shell *shell)
{
	shell->tokens = generate_tokens(line);
	if (!shell->tokens)
	{
		shell->exit_status = 1;
		return (2);
	}
	if (!is_syntax_correct(shell->tokens))
	{
		shell->exit_status = 2;
		free_tokens(shell->tokens);
		shell->tokens = NULL;
		return (1);
	}
	if (expansion(shell))
	{
		shell->exit_status = 1;
		free_tokens(shell->tokens);
		shell->tokens = NULL;
		return (2);
	}
	return (0);
}

static int	is_syntax_correct(t_token *tokens)
{
	if (!is_operator_syntax_correct(tokens))
	{
		print_error("minishell: syntax error near unexpected token!\n");
		return (0);
	}
	if (!is_quote_syntax_correct(tokens))
	{
		print_error("minishell: unclosed quotes!\n");
		return (0);
	}
	return (1);
}

static int	is_operator_syntax_correct(t_token *tokens)
{
	if (tokens->type == token_pipe)
		return (0);
	while (tokens)
	{
		if (tokens->type != token_word && tokens->type != token_pipe)
		{
			if (!tokens->next || tokens->next->type != token_word)
				return (0);
			tokens = tokens->next;
		}
		if (tokens->type == token_pipe)
		{
			if (!tokens->next || tokens->next->type == token_pipe)
				return (0);
		}
		tokens = tokens->next;
	}
	return (1);
}

static int	is_quote_syntax_correct(t_token *tokens)
{
	while (tokens)
	{
		if (!is_token_quote_correct(tokens->value))
			return (0);
		tokens = tokens->next;
	}
	return (1);
}

static int	is_token_quote_correct(char *value)
{
	size_t	i;
	char	quote;

	i = 0;
	while (value && value[i])
	{
		if (value[i] == '\'' || value[i] == '"')
		{
			quote = value[i++];
			while (value[i] && value[i] != quote)
				i++;
			if (value[i] != quote)
				return (0);
		}
		i++;
	}
	return (1);
}
