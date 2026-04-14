#include "prompt.h"

void	basic_prompt(t_shell *shell)
{
	char	*line;
	t_token	*tokens;

	line = readline("$ ");
	while (line)
	{
		tokens = generate_tokens(line);
		if (!tokens)
		{
			perror("minishell");
			shell->exit_status = 1;
			continue ;
		}
		print_tokens(tokens);
		if (expansion(tokens, shell))
		{
			perror("minishell");
			free_tokens(tokens);
			shell->exit_status = 1;
			continue ;
		}
		print_tokens(tokens);
		// execute(tokens, ev); to do later
		// free_token(tokens); to do later
		free(line);
		free_tokens(tokens);
		line = readline("$ ");
	}
}
