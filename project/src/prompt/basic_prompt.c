#include "prompt.h"

// void	run(char *line, t_env *ev);
// t_node	*parse(char *line);
t_token	*lexer(char *line);
void	print_tokens(t_token	*tokens);

void	basic_prompt(t_env *ev)
{
	char	*line;
	t_token	*tokens;
	(void) ev;
	line = readline("$ ");
	while (line)
	{
		// run(line, ev);
		tokens = lexer(line);
		print_tokens(tokens);
		printf("\n");
		free(line);
		line = readline("$ ");
	}
}

void	print_tokens(t_token	*tokens)
{
	while (tokens)
	{
		if (tokens->type == token_word)
			printf("[WORD: %s] ", tokens->value);
		else if (tokens->type == token_pipe)
			printf("[PIPE: %s] ", tokens->value);
		else if (tokens->type == token_redir_in)
			printf("[REDIR_IN: %s] ", tokens->value);
		else if (tokens->type == token_redir_out)
			printf("[REDIR_OUT: %s] ", tokens->value);
		else if (tokens->type == token_redir_app)
			printf("[REDIR_APP: %s] ", tokens->value);
		else if (tokens->type == token_here_doc)
			printf("[REDIR_HERE_DOC: %s] ", tokens->value);
		tokens = tokens->next;
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

t_token	*lexer(char *line)
{
	char	**splitted;
	t_token	*tokens;
	t_token	*tmp;
	t_token	*token;

	tokens = NULL;
	splitted = ft_split(line, ' ');
	while (*splitted)
	{
		token = (t_token *) malloc(sizeof(t_token));
		if (!token)
			return (NULL); // later add backward free
		if (!ft_strncmp(*splitted, "|", 2))
			token->type = token_pipe;
		else if (!ft_strncmp(*splitted, ">", 2))
			token->type = token_redir_out;
		else if (!ft_strncmp(*splitted, "<", 2))
			token->type = token_redir_in;
		else if (!ft_strncmp(*splitted, ">>", 3))
			token->type = token_redir_app;
		else if (!ft_strncmp(*splitted, "<<", 3))
			token->type = token_here_doc;
		else // burada öncesi için freeleme yapılabilir sonra
		{
			token->type = token_word;
			token->value = *splitted;
		}
		token->next = NULL;
		if (!tokens)
		{
			tokens = token;
			tmp = tokens;
		}
		else
		{
			tmp->next = token;
			tmp = tmp->next;
		}
		splitted++;
	}
	return (tokens);
}

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