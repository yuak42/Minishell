/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structures.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:32:27 by yuak              #+#    #+#             */
/*   Updated: 2026/05/19 18:01:36 by yuak             ###   ########.fr       */
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

typedef struct s_token {
	t_token_type	type;
	size_t			heredoc_exp;
	char			*value;
	struct s_token	*next;
} t_token;

typedef struct s_redir {
	t_token_type	type;
	char			*file;
	int				read;
	size_t			heredoc_exp;
	struct s_redir	*next;
} t_redir;

typedef struct s_node
{
    char            **argv;     // komut + argümanlar (execve için)
	t_redir			*redir;
    int				infile;    // <
    int				outfile;   // > veya >>
	int				heredoc;
    // int             *append;     // 1 ise >>, 0 ise >
    // int             *heredoc;    // << varsa 1

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
	char	*line;
} t_shell;



#endif