#include "prompt.h"

void	add_token_last(t_token **tokens, t_token *token)
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