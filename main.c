/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:06:59 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/03/17 18:52:14 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	if (parse_arguments(argc, argv) == PARSING_ERROR)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	return (0);
}
