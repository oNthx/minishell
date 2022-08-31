SRC =	$(shell find sources -name \*.c)

OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f
AR	 	= ar -rcs
NAME	= libft.a

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

.c.o:
	@$(CC) $(CFLAGS)  -c $< -o $@

clean:
	@$(RM) $(OBJ)
	
fclean:	clean
	@$(RM) $(NAME)

re:	fclean all


.PHONY: all $(NAME) clean fclean re
