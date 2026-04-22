#include "prompt.h"

static int	is_syntax_correct(t_token *tokens);
static t_token	*tokenizer(char *line, t_shell *shell);

void	basic_prompt(t_shell *shell)
{
	char	*line;
	t_token	*tokens;
	t_node	*nodes;

	line = readline("$ ");
	while (line)
	{
		tokens = tokenizer(line, shell);
		if (tokens)
		{
			nodes = create_nodes(tokens);
			if (nodes)
			{
				print_nodes(nodes);
				execute(nodes, shell);
				free_nodes(nodes);
			}
		}
		free_tokens(tokens);
		free(line); // always free at the end of loop
		line = readline("$ ");
	}
}

static t_token	*tokenizer(char *line, t_shell *shell)
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
		printf("syntax error!\n"); // print error maybe
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