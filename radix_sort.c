/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:59:05 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/05/30 17:34:12 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_node *stack_a, t_node *stack_b)
{
	int	stack_cardinality;
	int	significant_bits;
	int	i;
	int	j;

	stack_cardinality = stack_length(stack_a);
	significant_bits = 0;
	while ((stack_cardinality >> significant_bits) != 0)
		significant_bits++;
	i = 0;
	while (i < significant_bits)
	{
		j = 0;
		while (j < stack_cardinality)
		{
			if (((stack_a->next->cardinality >> i) & 1))
				rotate_a(stack_a);
			else
				push_b(stack_a, stack_b);
			j++;
		}
		while (stack_length(stack_b) > 0)
			push_a(stack_b, stack_a);
		i++;
	}
}
