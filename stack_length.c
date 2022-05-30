/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:55:37 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/05/30 17:00:37 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_length(t_node *stack_head)
{
	t_node	*node;
	int		stack_length;

	stack_length = 0;
	if (stack_head->next == stack_head)
		return (stack_length);
	else
		node = stack_head->next;
	stack_length++;
	while (node->next != stack_head)
	{
		stack_length++;
		node = node->next;
	}
	return (stack_length);
}
