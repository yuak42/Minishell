#include "prompt.h"

void	run(char *line);

void	basic_prompt(void)
{
	char	*line;
	
	printf("Welcome to msh!\n");
	line = readline("msh$ ");
	while (line)
	{
		run(line);
		// printf("You run this command: %s\n", line);
		free(line);
		line = readline("\033[34mmsh$ \033[0m");
	}
	clear_history();
}

void	run(char *line)
{
	t_node	node;

	(void) node;
	(void) line;

}