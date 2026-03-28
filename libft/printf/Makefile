NAME = libftprintf.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRC = fmt_char.c fmt_hex.c fmt_int.c fmt_ptr.c ft_printf.c
OBJ = $(SRC:.c=.o)
AR = ar rcs

all: $(NAME)

$(NAME):$(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re