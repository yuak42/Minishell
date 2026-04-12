#include "prompt.h"

static void	decide_token_type(t_token *token, char *str);
static t_token	*create_token(char *str, size_t start, size_t i, char state);
static void	add_token_next(t_token **tokens, t_token *token);

t_token	*generate_tokens(char *line)
{
	t_token	*tokens;
	t_token	*token;
	size_t	i;
	size_t	start;

	tokens = NULL;
	i = 0;
	start = 0;
	while (line[i])
	{

		if (line[i] == ' ')
		{
			token = create_token(line, start, i, ' ');
			while (line[i] == ' ' && line[i] != '\0')
				i++;
			start = i + 1;
			add_token_next(&tokens, token);
		}
		else if (line[i] == '"')
		{
			i++;
			start++;
			printf("(1) i: %ld\n", i);
			while (line[i] != '\0' && line[i] != '"')
				i++;
			printf("(2) i: %ld\n", i);
			if (line[i] == '"')
				token = create_token(line, start, i, '"');
			else
				printf("syntax error!"); // free everything later
			add_token_next(&tokens, token);
			start = i + 1;
		}



		// if (!token)
		// 	return (NULL); // should free later tokens

		i++;
	}
	if (start != i)
	{
		token = create_token(line, start, i, ' ');
		add_token_next(&tokens, token);
	}
	return (tokens);
}

static t_token	*create_token(char *str, size_t start, size_t i, char state)
{
	char	*value;
	t_token	*token;

	token = (t_token *) malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	value = ft_substr(str, start, i - start);
	// printf("substr -> %s\n", value);
	if (!value)
		return (NULL); //free later token
	token->value = value;
	if (state == ' ')
		token->state = normal;
	else if (state == '\'')
		token->state = quote_single;
	else if (state == '"')
		token->state = quote_double;
	decide_token_type(token, value);
	token->next = NULL;
	return (token);
}

static void	decide_token_type(t_token *token, char *str)
{
	if (!ft_strncmp(str, "|", 2))
		token->type = token_pipe;
	else if (!ft_strncmp(str, ">", 2))
		token->type = token_redir_out;
	else if (!ft_strncmp(str, "<", 2))
		token->type = token_redir_in;
	else if (!ft_strncmp(str, ">>", 3))
		token->type = token_redir_app;
	else if (!ft_strncmp(str, "<<", 3))
		token->type = token_here_doc;
	else
		token->type = token_word;
}

static void	add_token_next(t_token **tokens, t_token *token)
{
	t_token	*tmp;

	tmp = *tokens;
	if (!tmp)
		*tokens = token;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = token;
	}
}

// This is not efficient, later maybe change