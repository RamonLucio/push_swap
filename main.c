/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:06:59 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/05/31 00:58:22 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (are_there_invalid_arguments(argc, argv))
		return (1);
	stack_a = create_stack_a(argc, argv);
	stack_b = create_stack_b(stack_a);
	if (!is_sorted(stack_a))
	{
		if (stack_length(stack_a) == 2)
			swap_a(stack_a);
		else if (stack_length(stack_a) == 3)
			sort_three(stack_a);
		else if (stack_length(stack_a) <= 20)
			small_sort(stack_a, stack_b);
		else
			radix_sort(stack_a, stack_b);
	}
	free_stack(stack_a);
	free(stack_b);
	return (0);
}
