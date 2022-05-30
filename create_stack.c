/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:57:56 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/05/30 17:08:53 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_stack(int number, t_node *head)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		exit(EXIT_FAILURE);
	new_node->element = number;
	new_node->cardinality = -1;
	if (head->next == NULL)
	{
		head->previous = new_node;
		new_node->next = head;
	}
	else
	{
		new_node->next = head->next;
		(head->next)->previous = new_node;
	}
	head->next = new_node;
	new_node->previous = head;
}

static int	are_there_any_elements_without_cardinality(t_node *stack_head)
{
	t_node	*node;

	node = stack_head->next;
	while (node->next != stack_head)
	{
		if (node->cardinality == -1)
			return (1);
		node = node->next;
	}
	if (node->cardinality == -1)
		return (1);
	return (0);
}

static void	set_cardinality(t_node *stack_head)
{
	t_node		*node;
	t_node		*smallest;
	static int	cardinality;

	cardinality = 1;
	while (are_there_any_elements_without_cardinality(stack_head))
	{
		node = stack_head->next;
		while (node->cardinality != -1)
			node = node->next;
		smallest = node;
		while (node->next != stack_head)
		{
			if (node->next->element < smallest->element
				&& node->next->cardinality == -1)
				smallest = node->next;
			node = node->next;
		}
		smallest->cardinality = cardinality;
		cardinality++;
	}
}

t_node	*create_stack_a(int argc, char *argv[])
{
	t_node	*stack_head;
	int		index;

	stack_head = malloc(sizeof(t_node));
	if (stack_head == NULL)
		exit(EXIT_FAILURE);
	stack_head->next = NULL;
	stack_head->previous = NULL;
	index = argc - 1;
	while (argv[index] != argv[0])
	{
		push_to_stack(ft_atoi(argv[index]), stack_head);
		index--;
	}
	set_cardinality(stack_head);
	return (stack_head);
}

t_node	*create_stack_b(t_node *stack_a)
{
	t_node	*stack_b;

	stack_b = malloc(sizeof(t_node));
	if (stack_b == NULL)
	{
		free(stack_a);
		exit(EXIT_FAILURE);
	}
	stack_b->next = NULL;
	stack_b->previous = NULL;
	return (stack_b);
}
