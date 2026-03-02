NAME = minishell

SRC = prompt/basic_prompt.c main.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Iinclude -Wall -Wextra -Werror
LIBS = -lreadline

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cc $(OBJ) $(LIBS) $(LIBFT) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re