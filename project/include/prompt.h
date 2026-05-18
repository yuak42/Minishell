/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:32:31 by yuak              #+#    #+#             */
/*   Updated: 2026/05/18 18:54:04 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include "../src/pip_src/pipex.h"

void	basic_prompt(t_shell *shell);
t_env	*get_env_list(char **env);
void	free_ev(t_env *ev);
char	*get_env_value(t_env *ev, char *key);
void	add_env_to_last(t_env **head, t_env *node);
int		set_env_value(t_env *ev, char *key, char *value);
void	free_env_node(t_env *node);
t_token	*generate_tokens(char *line);
void	add_token_last(t_token **tokens, t_token *token);
void	free_tokens(t_token *tokens);
void	free_token(t_token *token);
void	remove_token(t_token **head, t_token *token);
t_token	*get_word(char *line, size_t *i);
t_token *get_operator(char *line, size_t *i);
int		expansion(t_shell *shell);
void	change_invalid_identifier(char **str);
void	change_to_none(char **str, char *var_name);
void	change_to_exit_status(char **str, int exit_status);
t_node	*create_nodes(t_token *tokens);
void	free_nodes(t_node *nodes);
void	add_last_node(t_node **head, t_node *node);
int		is_only_spaces(char *line);
t_token	*tokenizer(char *line, t_shell *shell);
void	print_error(char *s);
int		is_varchar(char c);
int		is_start_varchar(char c);
char	*get_key_name(char *str, size_t *i);
char	*connect_str(char *before, char *to_add);
int		expand(char **str, t_shell *shell);
char	*replace_exp(char *str, char *res, size_t start, size_t *i, t_shell *shell);
char	*connect_exp(char *res, char *key, t_shell *shell);
int		get_state(char c, int quote);
int		remove_quotes(char **str, t_token *token, t_token **head);

void	heredoc_sigint(int sig);
void	set_child_signals(void);
void	set_interactive_signals(void);
void	sigint_handler(int sig);

// To be deleted later
void	print_tokens(t_token	*tokens);
void	print_nodes(t_node *nodes);
void	print_ev(t_env *ev);

#endif