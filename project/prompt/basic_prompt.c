#include "prompt.h"

void	basic_prompt(void)
{
	char	*line;
	
	line = readline("msh$ ");
	if (line)
	{
		printf("%s", line);
		free(line);
	}
	clear_history();
}