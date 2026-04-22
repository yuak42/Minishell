#include "prompt.h"

static int	is_syntax_correct(t_token *tokens);

void	basic_prompt(t_shell *shell)
{
	char	*line;
	t_token	*tokens;
	t_node	*nodes;

	line = readline("$ ");
	while (line)
	{
		tokens = generate_tokens(line);
		if (!tokens)
		{
			shell->exit_status = 1;
			free(line);
			line = readline("$ ");
			continue ;
		}
		// print_tokens(tokens);
		if (expansion(tokens, shell))
		{
			perror("minishell");
			free_tokens(tokens);
			shell->exit_status = 1;
			free(line);
			line = readline("$ ");
			continue ;
		}
		// print_tokens(tokens);
		if (!is_syntax_correct(tokens))
		{
			printf("syntax error!\n"); // print error maybe
			shell->exit_status = 1;
		}
		else
		{
			nodes = create_nodes(tokens);
			print_nodes(nodes);
			shell->exit_status = 0;
			execute(nodes, shell);
			free_nodes(nodes);
		}
		free_tokens(tokens);
		free(line);
		line = readline("$ ");
	}
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