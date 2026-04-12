#include "prompt.h"

// void	run(char *line, t_env *ev);
// t_node	*parse(char *line);

void	basic_prompt(t_env *ev)
{
	char	*line;
	t_token	*tokens;
	(void) ev;
	line = readline("$ ");
	while (line)
	{
		// run(line, ev);
		tokens = generate_tokens(line);
		print_tokens(tokens);
		// execute(tokens, ev); to do later
		// free_token(tokens); to do later
		free(line);
		line = readline("$ ");
	}
}
