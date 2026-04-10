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

#endif