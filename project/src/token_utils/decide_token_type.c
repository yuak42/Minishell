#include "prompt.h"

void	decide_token_type(t_token *token, char *str)
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
