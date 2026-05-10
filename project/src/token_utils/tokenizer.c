/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:49:03 by yuak              #+#    #+#             */
/*   Updated: 2026/05/10 12:53:00 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_syntax_correct(t_token *tokens);

t_token	*tokenizer(char *line, t_shell *shell)
{
	t_token	*tokens;

	tokens = generate_tokens(line);
	if (!tokens)
	{
		shell->exit_status = 1;
		return (NULL);
	}
	if (expansion(tokens, shell))
	{
		free_tokens(tokens);
		shell->exit_status = 1;
		return (NULL);
	}
	if (!is_syntax_correct(tokens))
	{
		print_error("syntax error!\n");
		shell->exit_status = 1;
		return (NULL);
	}
	return (tokens);
}

static int	is_syntax_correct(t_token *tokens)
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