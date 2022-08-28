# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bozgur <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 15:18:38 by bozgur            #+#    #+#              #
#    Updated: 2022/08/27 18:56:37 by bozgur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(shell find sources -type f -name "*.c")
OBJS	= $(SRCS:sources/%.c=sources/%.o)

INC_FT	= ./libft/sources
INC_GN	= ./libft/GNL/sources
INC_PR	= ./libft/ft_printf/sources

CC		= gcc
RM		= rm -rf
CFLS	= -Wall -Werror -Wextra -I./inc
LDFLGS	= -L./lib/readline/lib -lreadline
LIBFT	= ./libft/libft.a
INC		= ./inc
NAME	= minishell

SRC		= sources/

all:	$(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft

$(SRC)%.o: $(SRC)%.c
	$(CC) $(CFLS) -c $< -o $@ -I$(INC) -I$(INC_FT) -I$(INC_GN) -I$(INC_PR)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LDFLGS) $(LIBFT)

clean:
	@$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

ffclean: fclean
	@make fclean -C ./libft

re: ffclean all

run: $(NAME)
	@./$(NAME)

.PHONY: all clean fclean re run
