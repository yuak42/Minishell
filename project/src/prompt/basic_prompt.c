#include "prompt.h"

void	run(char *line, t_env *ev);
t_node	*parse(char *line);

void	basic_prompt(t_env *ev)
{
	char	*line;
	(void) ev;
	line = readline("$ ");
	while (line)
	{
		run(line, ev);
		free(line);
		line = readline("$ ");
	}
}

void	run(char *line, t_env *ev)
{
	t_node	*node;

	node = parse(line);
	if (!node)
		return ; // command not working falan bişi yazcak mı?
	execute(node, ev); // to do later

	(void) node;
	(void) line;

}

t_node	*parse(char *line)
{
	t_node	*node;

	node = (t_node *) malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->token = comm;
	node->args = ft_split(line, ' '); // free later after execution
	node->stdin = 1;
	node->stdout = 0;
	return (node);
}
