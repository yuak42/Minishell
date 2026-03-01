#ifndef NODES_H
#define NODES_H

typedef enum e_token {
	comm,
	pipe_op,
	redi_op,
	dire_op
} t_token;

typedef struct s_node {
	t_token 		token;
	struct s_node	*left;
	struct s_node	*right;
	char			*args;
} t_node;

#endif