/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:10:58 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/04/06 18:11:26 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *head)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*third_node;

	if (head->next == NULL || head->next->next == head)
		return ;
	first_node = head->next;
	second_node = first_node->next;
	if (second_node->next != head)
		third_node = second_node->next;
	else
		third_node = head;
	second_node->next = first_node;
	second_node->previous = head;
	first_node->previous = second_node;
	first_node->next = third_node;
	third_node->previous = first_node;
	head->next = second_node;
}

void	push(t_node *popped_stack, t_node *pushed_stack)
{
	t_node	*popped_node;
	t_node	*top_node;

	if (popped_stack->next == NULL)
		return ;
	popped_node = popped_stack->next;
	popped_stack->next = popped_node->next;
	if (pushed_stack->next != NULL)
		top_node = pushed_stack->next;
	else
		top_node = pushed_stack;
	popped_node->next = top_node;
	popped_node->previous = pushed_stack;
	top_node->previous = popped_node;
	pushed_stack->next = popped_node;
}

void	rotate(t_node *head)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*last_node;

	if (head->next == NULL || head->next->next == head)
		return ;
	first_node = head->next;
	second_node = first_node->next;
	if (head->previous != second_node)
		last_node = head->previous;
	else
		last_node = second_node;
	head->next = second_node;
	head->previous = first_node;
	second_node->previous = head;
	first_node->next = head;
	first_node->previous = last_node;
	last_node->next = first_node;
}

void	reverse(t_node *head)
{
	t_node	*first_node;
	t_node	*last_node;
	t_node	*penultimate_node;

	if (head->next == NULL || head->next->next == head)
		return ;
	first_node = head->next;
	last_node = head->previous;
	if (last_node->previous != first_node)
		penultimate_node = last_node->previous;
	else
		penultimate_node = first_node;
	first_node->previous = last_node;
	last_node->next = first_node;
	last_node->previous = head;
	penultimate_node->next = head;
	head->next = last_node;
	head->previous = penultimate_node;
}
