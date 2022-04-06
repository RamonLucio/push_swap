/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:47:46 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/04/06 18:14:49 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				element;
	struct s_node	*next;
	struct s_node	*previous;
}				t_node;

t_node	*create_stack(int argc, char *argv[]);
int		are_the_args_invalid(int argc, char *argv[]);
int		are_there_duplicates(int argc, char *argv[]);
void	swap(t_node *head);
void	push(t_node *popped_stack, t_node *pushed_stack);
void	rotate(t_node *head);
void	reverse(t_node *head);

#endif