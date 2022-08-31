SRC	= $(shell find sources -name \*.c)
OBJ	= $(patsubst %.c, %.o, $(SRC))

NAME		= minihsell
CC			= gcc
RM			= rm -f
FLS			= -Wall -Werror -Wextra -I./lib/readline/include
LDFLAGS		= -L./lib/readline/lib -lreadline
LIBFT		= ./libft/libft.a

INC_FT		= ./libft/sources
INC_GN		= ./libft/GNL/sources
INC_PR		= ./libft/ft_printf/sources
INC			= ./inc/
LIB			= ./lib/.minishell

all: $(LIB) $(LIBFT) $(NAME)

$(LIBFT):
	@make -C ./libft

$(LIB):
	@make -C ./lib

.c.o:
	@$(CC) $(FLS) -c $< -o $@ -I$(INC_PR) -I$(INC_GN) -I$(INC_FT) -I$(INC)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME) $(LIBFT)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
