#include "prompt.h"

void	fill_args(char **argv, t_token *tokens);
size_t	get_args_len(t_token *tokens);
t_node	*create_node(t_token *tokens);
void	get_token_end(t_token **tokens);
char	*get_infile(t_token *tokens, t_node *node);
char	*get_outfile(t_token *tokens, t_node *node);

t_node	*create_nodes(t_token *tokens)
{
	t_node	*head;
	t_node	*node;

	head = NULL;
	printf("was here\n");
	while (tokens)
	{
		node = create_node(tokens);
		if (!node)
			return (free_nodes(head), NULL);
		printf("(1)\n");
		add_last_node(&head, node);
		printf("(2)\n");
		get_token_end(&tokens);
		if (!tokens)
			break ;
		if (tokens->type == token_pipe)
			node->pipe_out = 1;
		printf("(3)\n");
	}
	printf("create_nodes end\n");
	return (head);
}

t_node	*create_node(t_token *tokens)
{
	t_node	*node;
	char	**argv;
	size_t	argv_len;

	node = (t_node *) malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->pipe_in = 0;
	node->pipe_out = 0;
	if (tokens->type == token_pipe)
	{
		node->pipe_in = 1;
		tokens = tokens->next;
	}
	argv_len = get_args_len(tokens);
	argv = (char **) malloc(sizeof(char *) * (argv_len + 1));
	if (!argv)
		return (free(node), NULL);
	fill_args(argv, tokens);
	node->argv = argv;
	node->append = 0;
	node->heredoc = 0;
	node->infile = get_infile(tokens, node);
	node->outfile = get_outfile(tokens, node);
	node->next = NULL;
	return (node);
}

size_t	get_args_len(t_token *tokens)
{
	size_t	l;

	l = 0;
	while (tokens && tokens->type == token_word)
	{
		tokens = tokens->next;
		l++;
	}
	return (l);
}

void	fill_args(char **argv, t_token *tokens)
{
	size_t	i;

	i = 0;
	while (tokens && tokens->type == token_word)
	{
		argv[i] = tokens->value;
		i++;
		tokens = tokens->next;
	}
	argv[i] = NULL;
}

void	get_token_end(t_token **tokens)
{
	if (!*tokens)
		return ;
	if ((*tokens)->type == token_pipe)
		*tokens = (*tokens)->next;
	while (*tokens && (*tokens)->type != token_pipe)
		*tokens = (*tokens)->next;
}

char	*get_infile(t_token *tokens, t_node *node)
{
	while (tokens && tokens->type == token_word)
	{
		tokens = tokens->next;
	}
	if (!tokens)
		return (NULL);
	if (tokens->type == token_redir_in)
		return (tokens->next->value);
	if (tokens->type == token_heredoc)
	{
		node->heredoc = 1;
		return (tokens->next->value);
	}
	return (NULL);
}

char	*get_outfile(t_token *tokens, t_node *node)
{
	while (tokens && tokens->type == token_word)
	{
		tokens = tokens->next;
	}
	if (!tokens)
		return (NULL);
	if (tokens->type == token_redir_out)
		return (tokens->next->value);
	if (tokens->type == token_redir_app)
	{
		node->append = 1;
		return (tokens->next->value);
	}
	return (NULL);
}