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

void	basic_prompt(t_shell *shell);
t_env	*get_env_list(char **env);
void	free_ev(t_env *ev);
char	*get_env_value(t_env *ev, char *key);
void	set_env_value(t_env *ev, char *key, char *value);
void	free_env_node(t_env *node);
t_token	*generate_tokens(char *line);
void	add_token_last(t_token **tokens, t_token *token);
void	decide_token_type(t_token *token, char *str);
t_token	*create_token(char *str, size_t s, size_t i, char state);
void	free_tokens(t_token *tokens);
int		normal(t_token **tokens, char *line, size_t *s, size_t *i);
int		quote(t_token **tokens, char *line, size_t *s, size_t *i, char q);
int		get_token(t_token **tokens, char *line, size_t *s, size_t *i);
int		expansion(t_token *tokens, t_shell *shell);
void	replace(char **str, char *var_name, t_env *ev);
void	change_invalid_identifier(char **str);
void	change_to_none(char **str, char *var_name);
void	change_to_exit_status(char **str, int exit_status);
t_node	*create_nodes(t_token *tokens);
void	free_nodes(t_node *nodes);
void	add_last_node(t_node **head, t_node *node);
int		is_only_spaces(char *line);

// To be deleted later
void	print_tokens(t_token	*tokens);
void	print_nodes(t_node *nodes);

#endif