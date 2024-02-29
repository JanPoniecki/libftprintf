CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = libftprintf.a

SRC_FILES = ft_printf.c count_args.c print_stuff.c
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C libft
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
