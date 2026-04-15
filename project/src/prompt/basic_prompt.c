#include "prompt.h"

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
			line = readline("$ ");
			continue ;
		}
		print_tokens(tokens);
		if (expansion(tokens, shell))
		{
			perror("minishell");
			free_tokens(tokens);
			shell->exit_status = 1;
			line = readline("$ ");
			continue ;
		}
		print_tokens(tokens);
		nodes = create_nodes(tokens);
		print_nodes(nodes);
		// execute(tokens, shell);
		free(line);
		shell->exit_status = 0;
		line = readline("$ ");
		free_tokens(tokens);
	}
}
