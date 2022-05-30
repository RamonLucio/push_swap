/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:10:58 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/05/11 13:45:25 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node *stack_a)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*third_node;

	if (stack_a->next == NULL || stack_a->next->next == stack_a)
		return ;
	first_node = stack_a->next;
	second_node = first_node->next;
	if (second_node->next != stack_a)
		third_node = second_node->next;
	else
		third_node = stack_a;
	second_node->next = first_node;
	second_node->previous = stack_a;
	first_node->previous = second_node;
	first_node->next = third_node;
	third_node->previous = first_node;
	stack_a->next = second_node;
	write(1, "sa\n", 3);
}

void	push_a(t_node *stack_b, t_node *stack_a)
{
	t_node	*popped_node;
	t_node	*top_node;

	if (stack_b->next == NULL)
		return ;
	popped_node = stack_b->next;
	stack_b->next = popped_node->next;
	if (stack_a->next != NULL)
		top_node = stack_a->next;
	else
		top_node = stack_a;
	popped_node->next = top_node;
	popped_node->previous = stack_a;
	top_node->previous = popped_node;
	stack_a->next = popped_node;
	write(1, "pa\n", 3);
}

void	rotate_a(t_node *stack_a)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*last_node;

	if (stack_a->next == NULL || stack_a->next->next == stack_a)
		return ;
	first_node = stack_a->next;
	second_node = first_node->next;
	if (stack_a->previous != second_node)
		last_node = stack_a->previous;
	else
		last_node = second_node;
	stack_a->next = second_node;
	stack_a->previous = first_node;
	second_node->previous = stack_a;
	first_node->next = stack_a;
	first_node->previous = last_node;
	last_node->next = first_node;
	write(1, "ra\n", 3);
}

void	reverse_a(t_node *stack_a)
{
	t_node	*first_node;
	t_node	*last_node;
	t_node	*penultimate_node;

	if (stack_a->next == NULL || stack_a->next->next == stack_a)
		return ;
	first_node = stack_a->next;
	last_node = stack_a->previous;
	if (last_node->previous != first_node)
		penultimate_node = last_node->previous;
	else
		penultimate_node = first_node;
	first_node->previous = last_node;
	last_node->next = first_node;
	last_node->previous = stack_a;
	penultimate_node->next = stack_a;
	stack_a->next = last_node;
	stack_a->previous = penultimate_node;
	write(1, "rra\n", 4);
}
