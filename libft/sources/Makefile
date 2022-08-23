# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bozgur <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/31 03:01:24 by bozgur            #+#    #+#              #
#    Updated: 2022/08/21 23:56:57 by bozgur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= $(wildcard *.c)

OBJ 	=	$(SRC:.c=.o)

CC  	=	gcc
RM		=	rm -f
AR		= 	ar -rcs
FLS 	=	-Wall -Wextra -Werror
NAME	=	libft.a

all: $(NAME)

$(NAME):
	@$(CC) -c $(FLS) $(SRC)
	@$(AR) $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
