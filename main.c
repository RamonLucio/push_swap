/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:06:59 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/03/17 23:00:35 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*head_of_stack_a;

	if (parse_arguments(argc, argv) == PARSING_ERROR)
	{
		write(STDERR_FILENO, "Error\n", 7);
		return (PARSING_ERROR);
	}
	head_of_stack_a = create_stack(argc, argv);
	(void) head_of_stack_a;
	return (0);
}
