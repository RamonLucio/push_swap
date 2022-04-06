/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:06:59 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/04/06 18:15:40 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h> // NÃO ESQUECER DE REMOVER

int	main(int argc, char *argv[])
{
	t_node	*stack_a_head;
	t_node	*stack_b_head;

	if (argc == 1)
		return (1);
	if (are_the_args_invalid(argc, argv) || are_there_duplicates(argc, argv))
	{
		write(STDERR_FILENO, "Error\n", 7);
		return (1);
	}
	stack_a_head = create_stack(argc, argv);
	stack_b_head = malloc(sizeof(t_node));
	if (stack_b_head == NULL)
	{
		free(stack_a_head);
		exit(EXIT_FAILURE);
	}
	stack_b_head->next = NULL;
	stack_b_head->previous = NULL;
	return (0);
}
