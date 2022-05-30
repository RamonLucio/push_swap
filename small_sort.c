/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:41:27 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/05/30 23:21:48 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_smallest(t_node *stack_head)
{
	t_node	*node;
	int		smallest_element;

	node = stack_head->next;
	smallest_element = node->element;
	while (node->next != stack_head)
	{
		if (node->next->element < smallest_element)
			smallest_element = node->next->element;
		node = node->next;
	}
	if (node->element < smallest_element)
		smallest_element = node->element;
	return (smallest_element);
}

static int	get_biggest(t_node *stack_head)
{
	t_node	*node;
	int		biggest_element;

	node = stack_head->next;
	biggest_element = node->element;
	while (node->next != stack_head)
	{
		if (biggest_element < node->next->element)
			biggest_element = node->next->element;
		node = node->next;
	}
	if (biggest_element < node->element)
		biggest_element = node->element;
	return (biggest_element);
}

static int	find_smallest_element_position(t_node *stack_head)
{
	int		smallest_element;
	t_node	*node;
	int		position;

	smallest_element = get_smallest(stack_head);
	node = stack_head->next;
	position = 1;
	while (node->element != smallest_element)
	{
		position++;
		node = node->next;
	}
	return (position);
}

void	sort_three(t_node *stack_a)
{
	if (stack_a->next->element == get_smallest(stack_a))
	{
		reverse_a(stack_a);
		swap_a(stack_a);
	}
	else if (stack_a->next->element == get_biggest(stack_a))
	{
		rotate_a(stack_a);
		if (!is_sorted(stack_a))
			swap_a(stack_a);
	}
	else
	{
		if (stack_a->previous->element == get_biggest(stack_a))
			swap_a(stack_a);
		else
			reverse_a(stack_a);
	}
}

void	small_sort(t_node *stack_a, t_node *stack_b)
{
	while (stack_length(stack_a) > 2)
	{
		if (stack_a->next->element == get_biggest(stack_a)
			|| stack_a->next->element == get_smallest(stack_a))
			rotate_a(stack_a);
		else
			push_b(stack_a, stack_b);
	}
	while (stack_length(stack_b) > 0)
	{
		if (stack_b->next->element > stack_a->previous->element
			&& stack_b->next->element < stack_a->next->element)
			push_a(stack_b, stack_a);
		else if (stack_b->next->element > stack_a->next->element)
			rotate_a(stack_a);
		else
			reverse_a(stack_a);
	}
	while (get_smallest(stack_a) != stack_a->next->element)
	{
		if (find_smallest_element_position(stack_a) <= 3)
			rotate_a(stack_a);
		else
			reverse_a(stack_a);
	}
}
