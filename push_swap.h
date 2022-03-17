/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:47:46 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/03/17 22:59:39 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define UNSPECIFIED_ARG 1
# define INVALID_ARG 1
# define DUPLICATE_ARG 1
# define PARSING_ERROR 1

typedef struct s_node
{
	int				element;
	struct s_node	*next;
	struct s_node	*previous;
}				t_node;

t_node	*create_stack(int argc, char *argv[]);
int		parse_arguments(int argc, char *argv[]);

#endif