# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdorazio <jdorazio@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 15:33:02 by jdorazio          #+#    #+#              #
#    Updated: 2024/09/30 09:11:56 by jdorazio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

#  find *.c | xargs echo

C_FILES =  ft_printf.c ft_utils.c
O_FILES = $(C_FILES:.c=.o)

INCLUDE = ft_printf.h

CC = cc

CFLAGS += -Wall -Werror -Wextra -I.

all: $(NAME)

$(NAME): $(O_FILES)  $(INCLUDE)
		ar rcs $(NAME) $(O_FILES)

%.o : %.cc
	$(CC)  $(CFLAGS) -c $< -o $@

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
