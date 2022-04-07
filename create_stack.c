/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:57:56 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/04/07 20:02:43 by rlucio-l         ###   ########.fr       */
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
	return (stack_head);
}
