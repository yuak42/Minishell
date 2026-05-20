/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structures.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:32:27 by yuak              #+#    #+#             */
/*   Updated: 2026/05/20 16:36:26 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTURES_H
# define DATA_STRUCTURES_H

typedef enum e_token_type
{
	token_word,
	token_pipe,
	token_redir_in,
	token_redir_out,
	token_redir_app,
	token_heredoc
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	size_t			heredoc_exp;
	char			*value;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_redir
{
	t_token_type	type;
	char			*file;
	int				read;
	size_t			heredoc_exp;
	struct s_redir	*next;
}	t_redir;

typedef struct s_node
{
	char			**argv;
	t_redir			*redir;
	int				infile;
	int				outfile;
	int				pipe_in;
	int				pipe_out;
	struct s_node	*next;
}	t_node;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef struct s_shell
{
	t_env	*ev;
	int		exit_status;
	t_token	*tokens;
	t_node	*nodes;
	char	*line;
}	t_shell;

typedef struct s_expansion
{
	char	*str;
	size_t	start;
	size_t	*i;
}	t_expansion;

#endif