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

// void	run(char *line, t_env *ev)
// {
// 	t_node	*node;

// 	node = parse(line);
// 	if (!node)
// 		return ; // command not working falan bişi yazcak mı?
// 	// execute(node, ev); // to do later

// 	(void) node;
// 	(void) line;

// }

// t_node	*parse(char *line)
// {
// 	t_node	*node;

// 	node = (t_node *) malloc(sizeof(t_node));
// 	if (!node)
// 		return (NULL);
// 	node->token = word;
// 	node->args = ft_split(line, ' '); // free later after execution
// 	node->stdin = 1;
// 	node->stdout = 0;
// 	return (node);
// }

// char	*get_token_value(t_token *token, char **splitted)
// {
// 	char	*value;
// 	char	**tmp_splitted;
// 	char	*tmp_str;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	tmp_splitted = splitted;
// 	if (*splitted[0] == '"')
// 	{
// 		token->quote = quote_double;

// 	}
// 	return NULL
// }
// burada şunu yapmaya çalış -> echo "deneme | asks" ---> [WORD, "deneme | asks"]