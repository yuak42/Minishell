MAKEFLAGS += --silent
NAME = builtin.a
CFLAGS = -Wall -Werror -Wextra
CC = cc
AR = ar rcs
SRC = echo.c\
			env.c\
			export.c\
			pwd.c\
			cd.c\
			unset.c

OBJ = $(SRC:.c=.o)
all = $(NAME)

all: $(NAME)
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	echo make run
clean: 
	rm -rf $(OBJ)
	echo make clean
fclean: clean
	rm -rf $(NAME)
	echo make fclean
re: fclean all
	echo make re

debug: 
	$(MAKE) fclean
	$(MAKE) all CFLAGS="$(CFLAGS) -g"
	echo make debug

main: debug 
	$(CC) $(CFLAGS) main.c $(NAME) ../libft/libft.a -o main

.PHONY: all clean fclean re debug