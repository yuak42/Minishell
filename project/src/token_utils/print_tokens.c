#include "prompt.h"

void	print_tokens(t_token	*tokens)
{
	while (tokens)
	{
		if (tokens->type == token_word)
		{
			if (tokens->state == normal)
				printf("[WORD: %s, NORMAL] ", tokens->value);
			else if (tokens->state == quote_single)
				printf("[WORD: %s, SINGLE_QUOTE] ", tokens->value);
			else
				printf("[WORD: %s, DOUBLE_QUOTE] ", tokens->value);
		}
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
	printf("\n");
}