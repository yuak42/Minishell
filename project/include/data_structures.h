#ifndef NODES_H
#define NODES_H

typedef enum e_token {
	word,
	operator
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