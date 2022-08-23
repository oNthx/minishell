# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bozgur <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/31 02:58:05 by bozgur            #+#    #+#              #
#    Updated: 2022/07/31 02:58:06 by bozgur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= $(wildcard sources/*.c)
OBJS			= $(SRCS:.c=.o)
NAME			= get_next_line.a
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

all : ${NAME}

	
$(NAME) : ${OBJS}
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

.c.o :
	${CC} ${CFLAGS} -c $< -o $@

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

norm :
	norminette sources/*.[ch]

re : fclean all

.PHONY: all clean fclean re .c.o
