MAKEFLAGS += --silent

NAME = minishell

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

SRC = prompt/basic_prompt.c main.c execution/execute.c  \
	built_in/env.c built_in/pwd.c built_in/echo.c  built_in/cd.c \
	built_in/export.c built_in/unset.c \
	env_utils/get_env_list.c env_utils/set_env_value.c env_utils/get_env_value.c env_utils/free_env_node.c \
	token_utils/generate_tokens.c token_utils/add_token_last.c \
	token_utils/get_token.c token_utils/free_tokens.c \
	expansion_utils/expansion.c expansion_utils/replace.c expansion_utils/change_func.c \
	env_utils/free_ev.c 


OBJ = $(SRC:.c=.o)

# daha sonra silinecek
include byaprak.mk
SRC += $(BYAPRAK_SRC)

include yuak.mk
SRC += $(YUAK_SRC)

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
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@ 
# -g flag'i daha sonra kaldır

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


debug: 
	$(MAKE) fclean
	$(MAKE) all CFLAGS="$(CFLAGS) -g"
	echo make debug

.PHONY: all clean fclean re debug