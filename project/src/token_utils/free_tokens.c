#include "prompt.h"

void	free_tokens(t_token *tokens)
{
	t_token	*tmp;

	while (tokens)
	{
		tmp = tokens;
		free(tokens->value);
		tokens = tokens->next;
		free(tmp);
	}
}