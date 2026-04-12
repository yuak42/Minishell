#include "prompt.h"

static t_token	*create_token(char *str, size_t start, size_t i, char state);
static int	normal(t_token **tokens, char *line, size_t *start, size_t *i);
static int	quote(t_token **tokens, char *line, size_t *start, size_t *i, char q);

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
			if (normal(&tokens, line, &start, &i))
				return (NULL); // free before what is malloced sonra
		}
		else if (line[i] == '"' || line[i] == '\'')
		{
			if (quote(&tokens, line, &start, &i, line[i]))
				return (NULL); // free before
		}
		i++;
	}
	if (start != i)
	{
		token = create_token(line, start, i, ' ');
		add_token_last(&tokens, token);
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
		token->state = state_normal;
	else if (state == '\'')
		token->state = state_quote_single;
	else if (state == '"')
		token->state = state_quote_double;
	decide_token_type(token, value);
	token->next = NULL;
	return (token);
}

static int	normal(t_token **tokens, char *line, size_t *start, size_t *i)
{
	t_token	*token;

	token = create_token(line, *start, *i, ' ');
	if (!token)
		return (1);
	while (line[*i] == ' ' && line[*i] != '\0')
		(*i)++;
	(*i)--;
	*start = *i + 1;
	add_token_last(tokens, token);
	return (0);
}

static int	quote(t_token **tokens, char *line, size_t *start, size_t *i, char q)
{
	t_token *token;

	(*i)++;
	(*start)++;
	while (line[*i] != '\0' && line[*i] != q)
		(*i)++;
	if (line[*i] == q)
	{
		token = create_token(line, *start, *i, q);
		if (!token)
			return (1); // add free later
	}
	else
		printf("syntax error!"); // free everything later print to stderr
	add_token_last(tokens, token);
	(*i)++;
	while (line[*i] == ' ' && line[*i] != '\0')
		(*i)++;
	(*i)--;
	*start = *i + 1;
	return (0);
}