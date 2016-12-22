# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mawasche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 17:11:11 by mawasche          #+#    #+#              #
#    Updated: 2016/12/10 15:44:11 by ele-cren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = src/ft_backtracking.c src/ft_create.c src/ft_map.c src/ft_putchar.c \
	  src/ft_putstr.c src/ft_check.c src/ft_extras.c src/main.c

OBJ = ft_backtracking.o ft_create.o ft_map.o ft_putchar.o ft_putstr.o \
	  ft_check.o ft_extras.o main.o

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC) -I includes
	gcc $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all
