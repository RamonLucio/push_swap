/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:30:56 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/04/20 16:35:30 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

static int	find_biggest_element(t_node *stack_head)
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

static int	find_smallest_element(t_node *stack_head)
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

static int	are_there_any_element_smaller_than_the_pivot(t_node *stack_head)
{
	t_node	*pivot;
	t_node	*node;

	pivot = stack_head->next;
	node = pivot->next;
	while (node->next != stack_head)
	{
		if (node->element < pivot->element)
			return (1);
		node = node->next;
	}
	if (node->element < pivot->element)
		return (1);
	return (0);
}

void	partition(t_node *stack_a, t_node *stack_b)
{
	int	operations;

	operations = 0;
	if (stack_a->next->element == find_biggest_element(stack_a)
		|| stack_a->next->element == find_smallest_element(stack_a))
		rotate(stack_a);
	while (are_there_any_element_smaller_than_the_pivot(stack_a))
	{
		if (stack_a->next->next->element < stack_a->next->element
			&& stack_a->next->next->element < stack_a->previous->element)
		{
			swap(stack_a);
			push(stack_a, stack_b);
		}
		else if (stack_a->previous->element < stack_a->next->element
			&& stack_a->previous->element < stack_a->next->next->element)
		{
			reverse(stack_a);
			push(stack_a, stack_b);
		}
		else
		{
			reverse(stack_a);
			swap(stack_a);
		}
		operations += 2;
	}
	printf("Operations: %i\n", operations);
}
