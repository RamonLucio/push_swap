/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:50:17 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/05/28 14:06:09 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*create_array(int argc, char *argv[])
{
	int	*array;
	int	argv_index;
	int	array_index;

	argv_index = argc - 1;
	array = malloc(argv_index * sizeof(int));
	if (array == NULL)
		exit(EXIT_FAILURE);
	array_index = argv_index - 1;
	while (argv[argv_index] != argv[0])
	{
		array[array_index] = ft_atoi(argv[argv_index]);
		argv_index--;
		array_index--;
	}
	return (array);
}

static int	are_there_duplicates(int argc, char *argv[])
{
	int	*array;
	int	i;
	int	j;

	array = create_array(argc, argv);
	i = 0;
	while (i < argc - 2)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (array[i] == array[j])
			{
				free(array);
				return (1);
			}
			j++;
		}
		i++;
	}
	free(array);
	return (0);
}

static int	are_the_args_integers(int argc, char *argv[])
{
	int	index;

	index = argc - 1;
	while (argv[index] != argv[0])
	{
		if (ft_atoi(argv[index]) == 1 && ft_strncmp(argv[index], "1", 2) != 0)
			return (1);
		index--;
	}
	return (0);
}

int	are_there_invalid_arguments(int argc, char *argv[])
{
	if (argc == 1)
		return (1);
	if (are_the_args_integers(argc, argv) || are_there_duplicates(argc, argv))
	{
		write(STDERR_FILENO, "Error\n", 7);
		return (1);
	}
	return (0);
}
