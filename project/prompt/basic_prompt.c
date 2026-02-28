#include "prompt.h"

void	basic_prompt(void)
{
	char	*line;
	
	printf("Welcome to msh!\n");
	line = readline("msh$ ");
	while (line)
	{
		printf("You run this command: %s\n", line);
		free(line);
		line = readline("msh$ ");
	}
	clear_history();
}