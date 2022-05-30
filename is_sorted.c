/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:19:32 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/05/30 23:20:18 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack_head)
{
	t_node	*compared_node;
	t_node	*node;

	compared_node = stack_head->next;
	node = compared_node->next;
	while (compared_node->next != stack_head)
	{
		while (node->next != stack_head)
		{
			if (compared_node->element > node->element)
				return (0);
			else
				node = node->next;
		}
		if (compared_node->element > node->element)
			return (0);
		compared_node = compared_node->next;
		node = compared_node->next;
	}
	return (1);
}
