# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bozgur <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/31 02:57:40 by bozgur            #+#    #+#              #
#    Updated: 2022/08/03 17:06:14 by bozgur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= $(wildcard sources/*.c)
OBJS			= $(SRCS:.c=.o)

INCS			= libft.h
NAME			= libft.a
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
LIB_GNL			= GNL/get_next_line.a
LIB_PRINT		= ft_printf/libftprintf.a


all : $(LIB_GNL) $(LIB_PRINT) ${NAME}

$(LIB_GNL):
	make -C ./GNL

$(LIB_PRINT):
	make -C ./ft_printf

$(NAME) : ${OBJS}
	cp $(LIB_GNL) ./$(NAME)
	cp $(LIB_PRINT) ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

.c.o :
	${CC} ${CFLAGS} -c $< -o $@

clean :
	${RM} ${OBJS}

fclean : clean
	make fclean -C ./GNL
	make fclean -C ./ft_printf
	${RM} ${NAME}

norm :
	norminette sources/*.[ch]

re : fclean all

.PHONY: all clean fclean re .c.o
