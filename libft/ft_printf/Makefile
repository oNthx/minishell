# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bozgur <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/31 02:59:59 by bozgur            #+#    #+#              #
#    Updated: 2022/07/31 03:00:00 by bozgur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(wildcard sources/*.c)
OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror 


all :  ${NAME}

$(NAME) : ${OBJS}
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

.c.o : 
	${CC} ${CFLAGS} -c $< -o $@ 

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re .c.o bonus
