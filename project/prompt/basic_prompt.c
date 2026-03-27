#include "prompt.h"

void	run(char *line);
t_node	parse(char *line);

void	basic_prompt(void)
{
	char	*line;
	
	printf("Welcome to msh!\n");
	line = readline("msh$ ");
	while (line)
	{
		run(line);
		free(line);
		line = readline("\033[34mmsh$ \033[0m");
	}
}

void	run(char *line)
{
	t_node	node;

	node = parse(line);
	execute(node); // to do later

	(void) node;
	(void) line;

}

t_node	parse(char *line)
{
	size_t	i;
	t_node	node;
	char	**split;

	node.token = comm;
	i = 0;
	split = ft_split(line, ' '); // free later after execution
	node.args = split;
	printf("Given command (node.args[0]): %s\n", *node.args);
	split++;
	printf("Given arguments: ");
	while (*split)
	{
		printf("%s ", *split);
		split++;
	}
	printf("\n");
	(void) split;
	(void) i;
	return (node);
}

/*

	msh$ cd <dir>
	msh$ echo <str>

*/