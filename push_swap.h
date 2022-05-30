/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:47:46 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/05/31 00:20:53 by rlucio-l         ###   ########.fr       */
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
	int				cardinality;
	struct s_node	*next;
	struct s_node	*previous;
}				t_node;

int		are_there_invalid_arguments(int argc, char *argv[]);
t_node	*create_stack_a(int argc, char *argv[]);
t_node	*create_stack_b(t_node *stack_a);
void	free_stack(t_node *stack_head);
int		is_sorted(t_node *stack_head);
void	push_a(t_node *stack_b, t_node *stack_a);
void	push_b(t_node *stack_a, t_node *stack_b);
void	reverse_a(t_node *stack_a);
void	reverse_b(t_node *stack_b);
void	rotate_a(t_node *stack_a);
void	rotate_b(t_node *stack_b);
void	swap_a(t_node *stack_a);
void	swap_b(t_node *stack_b);
void	radix_sort(t_node *stack_a, t_node *stack_b);
void	sort_three(t_node *stack_a);
void	small_sort(t_node *stack_a, t_node *stack_b);
int		stack_length(t_node *stack_head);

#endif