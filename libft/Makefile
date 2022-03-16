# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 17:36:55 by rlucio-l          #+#    #+#              #
#    Updated: 2022/03/16 17:41:28 by rlucio-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

SRC =	ft_atoi.c

OBJ =	${SRC:.c=.o}

CC =	gcc
CFLAGS +=	-Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
		ar rcs ${NAME} ${OBJ}

all:	${NAME}

clean:
		rm -f ${OBJ}

fclean: clean
		rm -f ${NAME}

re: 	fclean all

.PHONY: all clean fclean re