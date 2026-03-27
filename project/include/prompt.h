#ifndef PROMPT_H
#define PROMPT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "data_structures.h"
#include "../libft/libft.h"

void	basic_prompt(void);
void	execute(t_node node);

#endif