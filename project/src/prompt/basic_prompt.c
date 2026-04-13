#include "prompt.h"

// void	run(char *line, t_env *ev);
// t_node	*parse(char *line);

void	basic_prompt(t_shell *shell)
{
	char	*line;
	t_token	*tokens;

	line = readline("$ ");
	while (line)
	{
		// run(line, ev);
		tokens = generate_tokens(line);
		print_tokens(tokens);
		expansion(tokens, shell);
		print_tokens(tokens);
		// execute(tokens, ev); to do later
		// free_token(tokens); to do later
		free(line);
		line = readline("$ ");
	}
}
