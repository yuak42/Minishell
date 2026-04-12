#ifndef NODES_H
#define NODES_H

typedef enum e_token_type {
	token_word,
	token_pipe,
	token_redir_in,
	token_redir_out,
	token_redir_app,
	token_here_doc
} t_token_type;

typedef enum e_quote_type {
	quote_none,
	quote_single,
	quote_double
}

typedef struct s_token {
	t_token_type	type;
	char			*value;
	t_quote_type	quote;
	struct s_token	*next;
} t_token;

typedef struct s_node {
	t_token 		token;
	struct s_node	*left;
	struct s_node	*right;
	int				stdin;
	int				stdout;
	char			**args;
} t_node;

typedef struct s_env{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
} t_env;


#endif