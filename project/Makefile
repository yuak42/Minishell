NAME = minishell

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

SRC = prompt/basic_prompt.c main.c prompt/execute.c prompt/get_env_list.c \
	built_in/env.c built_in/pwd.c built_in/echo.c #built_in/export.c built_in/cd.c built_in/unset.c

OBJ = $(SRC:.c=.o)

SRC_P = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ_P = $(addprefix $(OBJ_DIR)/, $(OBJ))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
LIBS = -lreadline

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_P) 
	$(CC) $(OBJ_P) $(LIBS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@ 

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re