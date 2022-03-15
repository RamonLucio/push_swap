# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 18:59:01 by rlucio-l          #+#    #+#              #
#    Updated: 2022/03/15 20:26:36 by rlucio-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS += -Wall -Wextra -Werror

.c.o :
	$(CC) ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re