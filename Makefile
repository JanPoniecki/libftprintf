CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = libftprintf.a

SRC_FILES = ft_printf.c count_args.c print_stuff.c ft_putptr_fd.c ft_putud_fd.c ft_puthex_fd.c ft_putnbr_count.c ft_putstr_count.c
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	make clean -C libft
	rm -f $(OBJ_FILES)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
