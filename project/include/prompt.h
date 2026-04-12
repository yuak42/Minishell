#ifndef PROMPT_H
#define PROMPT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "data_structures.h"
#include "../libft/libft.h"
#include "builtin.h"

void	basic_prompt(t_env *ev);
void	execute(t_node *node, t_env *ev);
t_env	*get_env_list(char **env);
t_token	*generate_tokens(char *line);
void	add_token_last(t_token **tokens, t_token *token);
void	decide_token_type(t_token *token, char *str);



// To be deleted later
void	print_tokens(t_token	*tokens);

#endif