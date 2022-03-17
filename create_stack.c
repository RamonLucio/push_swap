/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:57:56 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/03/17 23:00:50 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(int number, t_node *head)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		exit(EXIT_FAILURE);
	new_node->element = number;
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

t_node	*create_stack(int argc, char *argv[])
{
	t_node	*head_of_stack_a;
	int		index;

	head_of_stack_a = malloc(sizeof(t_node));
	if (head_of_stack_a == NULL)
		exit(EXIT_FAILURE);
	head_of_stack_a->next = NULL;
	head_of_stack_a->previous = NULL;
	index = argc - 1;
	while (argv[index] != argv[0])
	{
		push(ft_atoi(argv[index]), head_of_stack_a);
		index--;
	}
	return (head_of_stack_a);
}
