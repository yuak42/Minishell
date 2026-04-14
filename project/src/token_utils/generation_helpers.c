#include "prompt.h"

t_token	*create_token(char *str, size_t s, size_t i, char state)
{
	char	*value;
	t_token	*token;

	token = (t_token *) malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	value = ft_substr(str, s, i - s);
	if (!value)
		return (free(token), NULL); //free later token
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

int	get_token(t_token **tokens, char *line, size_t *s, size_t *i)
{
	if (line[*i] == ' ')
	{
		if (normal(tokens, line, s, i))
			return (1);
	}
	else
	{
		if (quote(tokens, line, s, i, line[*i]))
			return (1);
	}
	return (0);
}

int	normal(t_token **tokens, char *line, size_t *s, size_t *i)
{
	t_token	*token;

	token = create_token(line, *s, *i, ' ');
	if (!token)
		return (1);
	while (line[*i] == ' ' && line[*i] != '\0')
		(*i)++;
	(*i)--;
	*s = *i + 1;
	add_token_last(tokens, token);
	return (0);
}

int	quote(t_token **tokens, char *line, size_t *s, size_t *i, char q)
{
	t_token *token;

	(*i)++;
	(*s)++;
	while (line[*i] != '\0' && line[*i] != q)
		(*i)++;
	if (line[*i] == q)
	{
		token = create_token(line, *s, *i, q);
		if (!token)
			return (1);
	}
	else
	{
		ft_perror("syntax error!%s\n", "");
		return (1);
	}
	add_token_last(tokens, token);
	(*i)++;
	while (line[*i] == ' ' && line[*i] != '\0')
		(*i)++;
	(*i)--;
	*s = *i + 1;
	return (0);
}
