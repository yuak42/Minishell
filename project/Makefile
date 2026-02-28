NAME = minishell

SRC = prompt/basic_prompt.c main.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Iinclude -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re