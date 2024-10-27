# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumugot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 16:53:49 by lumugot           #+#    #+#              #
#    Updated: 2024/10/24 13:19:31 by lumugot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = my_printf.c \
		my_utils.c \
		my_utils_bis.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS  = -Wall -Wextra -Werror -g

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
