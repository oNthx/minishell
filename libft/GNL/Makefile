SRC		= $(wildcard sources/*.c)
OBJ		= $(patsubst %.c, %.o, $(SRC))

NAME	= get_next_line.a
CC		= gcc
RM		= rm -rf
FLGS	= -Wall -Werror -Wextra

LIB		= ft_printf/libftprintf.a

all: $(LIB) $(NAME)

$(LIB):
	make -C ../ft_printf

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C ../ft_printf
	$(RM) $(NAME)

re:	fclean all

.PHONY: all re clean fclean
