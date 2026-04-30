#include "prompt.h"

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
		if (line[i] == ' ' || line[i] == '"' || line[i] == '\'')
		{
			if (get_token(&tokens, line, &start, &i))
				return (free_tokens(tokens), NULL);
		}
		i++;
	}
	if (start != i)
	{
		token = create_token(line, start, i, ' ');
		if (!token)
			return (free_tokens(tokens), NULL);
		add_token_last(&tokens, token);
	}
	return (tokens);
}
/*
Change tokenizer behaviour

move on the line with index i
keep a state that is it in quotes or not
if it encounters any of the operator while it is in state normal extract it
(check first << and >>)




*/