/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 00:18:50 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/05/31 01:00:11 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node *stack_head)
{
	t_node	*node;
	t_node	*next;

	node = stack_head->next;
	while (node != stack_head)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(stack_head);
}
