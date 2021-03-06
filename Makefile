# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 18:59:01 by rlucio-l          #+#    #+#              #
#    Updated: 2022/05/31 10:50:40 by rlucio-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

SRC =	create_stack.c \
		free_stack.c \
		is_sorted.c \
		main.c \
		parse_arguments.c \
		radix_sort.c \
		small_sort.c \
		stack_a_operations.c \
		stack_b_operations.c \
		stack_length.c \

OBJ =	$(SRC:.c=.o)

CC =	gcc
CFLAGS += -Wall -Wextra -Werror

.c.o:
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