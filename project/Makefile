NAME = minishell

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

SRC = prompt/basic_prompt.c main.c  \
	env_utils/get_env_list.c env_utils/set_env_value.c env_utils/get_env_value.c env_utils/free_env_node.c \
	token_utils/generate_tokens.c token_utils/add_token_last.c \
	token_utils/get_token.c token_utils/free_tokens.c \
	expansion_utils/expansion.c env_utils/free_ev.c \
 	built_in/export.c built_in/unset.c built_in/exit.c \
	built_in/env.c built_in/pwd.c built_in/echo.c  built_in/cd.c built_in/export_utils.c\
	execution/execute.c node_utils/create_nodes.c node_utils/free_nodes.c node_utils/add_last_node.c \
	prompt/is_only_spaces.c utils/print_error.c token_utils/tokenizer.c expansion_utils/varchar_utils.c expansion_utils/get_key_name.c \
	expansion_utils/expansion_helpers.c expansion_utils/expand.c expansion_utils/remove_quotes.c \
	utils/signal_utils.c env_utils/add_env_to_last.c token_utils/remove_token.c prompt/heredoc.c \
	prompt/heredoc_utils.c node_utils/add_arg.c node_utils/handle_op.c \
	execution/executor_utils.c execution/env_to_arry.c execution/env_size.c execution/free_str.c execution/ft_printf.c \
	pip_src/path.c pip_src/utils.c pip_src/utils2.c pip_src/pipex.c pip_src/ft_all_free.c pip_src/redirections.c pip_src/path_check.c \
	print_debug/print_nodes.c utils/free_shell.c prompt/free_parser.c prompt/parser.c prompt/prompt.c

OBJ = $(SRC:.c=.o)

SRC_P = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ_P = $(addprefix $(OBJ_DIR)/, $(OBJ))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
LIBS = -lreadline

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_P)
	$(CC) $(OBJ_P) $(LIBS) $(LIBFT) -o $(NAME)
	echo make run

$(LIBFT):
	make -C $(LIBFT_DIR)
	make -C $(LIBFT_DIR) bonus

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)
	echo make clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	echo make fclean

re: fclean all
	echo make re

.PHONY: all clean fclean re
