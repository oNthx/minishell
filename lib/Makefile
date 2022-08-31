# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bozgur <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 15:18:37 by bozgur            #+#    #+#              #
#    Updated: 2022/08/31 15:25:59 by bozgur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR		= $(shell echo $(PWD))
RM		= rm -rf

LIB		= ./.minishell

all: $(LIB)

fclean:
	@$(RM) ./readline $(LIB)

re: fclean all

$(LIB):
	@curl -O http://ftp.gnu.org/gnu/readline/readline-8.2-rc1.tar.gz
	@gunzip -c readline-8.2-rc1.tar.gz | tar xopf -
	@mv readline-8.2-rc1 readline
	/bin/sh -c "cd readline && sh ./configure --prefix=$(DIR)/readline"
	make install -C readline
	@rm -f readline-8.2-rc1.tar.gz
	@mkdir $(LIB)

.PHONY: all fclean re
