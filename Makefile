# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 18:59:01 by rlucio-l          #+#    #+#              #
#    Updated: 2022/03/17 18:51:41 by rlucio-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

SRC =	main.c parsing.c

OBJ =	$(SRC:.c=.o)

CC =	gcc
CFLAGS += -Wall -Wextra -Werror

.c.o :
		$(CC) ${CFLAGS} -c $< -o ${<:.c=.o}

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

$(NAME): $(LIBFT) $(OBJ)
		gcc -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
		make -C $(LIBFT_DIR)

all:	$(NAME)

clean:
		make -C $(LIBFT_DIR) clean
		rm -f $(OBJ)

fclean: clean
		make -C $(LIBFT_DIR) fclean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re libft