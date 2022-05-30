/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:49:47 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/05/27 15:23:14 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_node *stack_b)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*third_node;

	if (stack_b->next == NULL || stack_b->next->next == stack_b)
		return ;
	first_node = stack_b->next;
	second_node = first_node->next;
	if (second_node->next != stack_b)
		third_node = second_node->next;
	else
		third_node = stack_b;
	second_node->next = first_node;
	second_node->previous = stack_b;
	first_node->previous = second_node;
	first_node->next = third_node;
	third_node->previous = first_node;
	stack_b->next = second_node;
	write(1, "sb\n", 3);
}

void	push_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*popped_node;
	t_node	*top_node;

	if (stack_a->next == NULL)
		return ;
	popped_node = stack_a->next;
	stack_a->next = popped_node->next;
	if (stack_b->next != NULL)
		top_node = stack_b->next;
	else
		top_node = stack_b;
	popped_node->next = top_node;
	popped_node->previous = stack_b;
	top_node->previous = popped_node;
	stack_b->next = popped_node;
	write(1, "pb\n", 3);
}

void	rotate_b(t_node *stack_b)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*last_node;

	if (stack_b->next == NULL || stack_b->next->next == stack_b)
		return ;
	first_node = stack_b->next;
	second_node = first_node->next;
	if (stack_b->previous != second_node)
		last_node = stack_b->previous;
	else
		last_node = second_node;
	stack_b->next = second_node;
	stack_b->previous = first_node;
	second_node->previous = stack_b;
	first_node->next = stack_b;
	first_node->previous = last_node;
	last_node->next = first_node;
	write(1, "rb\n", 3);
}

void	reverse_b(t_node *stack_b)
{
	t_node	*first_node;
	t_node	*last_node;
	t_node	*penultimate_node;

	if (stack_b->next == NULL || stack_b->next->next == stack_b)
		return ;
	first_node = stack_b->next;
	last_node = stack_b->previous;
	if (last_node->previous != first_node)
		penultimate_node = last_node->previous;
	else
		penultimate_node = first_node;
	first_node->previous = last_node;
	last_node->next = first_node;
	last_node->previous = stack_b;
	penultimate_node->next = stack_b;
	stack_b->next = last_node;
	stack_b->previous = penultimate_node;
	write(1, "rrb\n", 4);
}
