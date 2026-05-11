/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structures.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:32:27 by yuak              #+#    #+#             */
/*   Updated: 2026/05/11 15:51:25 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODES_H
#define NODES_H

typedef enum e_token_type {
	token_word,
	token_pipe,
	token_redir_in,
	token_redir_out,
	token_redir_app,
	token_heredoc
} t_token_type;

typedef enum e_state {
	state_normal,
	state_quote_single,
	state_quote_double
} t_state;

typedef struct s_token {
	t_token_type	type;
	char			*value;
	struct s_token	*next;
} t_token;

typedef struct s_node
{
    char            **argv;     // komut + argümanlar (execve için)
    
    char            *infile;    // <
    char            *outfile;   // > veya >>
    int             append;     // 1 ise >>, 0 ise >
    int             heredoc;    // << varsa 1

    int             pipe_in;    // önceki pipeden input alıyor mu
    int             pipe_out;   // sonraki pipe'a output veriyor mu

    struct s_node   *next;
}   t_node;

typedef struct s_env {
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
} t_env;

typedef struct s_shell {
	t_env	*ev;
	int		exit_status;
	t_token	*tokens;
	t_node	*nodes;
} t_shell;


#endif