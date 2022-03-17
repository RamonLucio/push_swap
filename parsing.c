/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:50:17 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/03/17 18:52:06 by rlucio-l         ###   ########.fr       */
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
				return (DUPLICATE_ARG);
			}
			j++;
		}
		i++;
	}
	free(array);
	return (0);
}

int	parse_arguments(int argc, char *argv[])
{
	int	index;

	if (argc == 1)
		return (UNSPECIFIED_ARG);
	index = argc - 1;
	while (argv[index] != argv[0])
	{
		if (ft_atoi(argv[index]) == INVALID_ARG
			&& ft_strncmp(argv[index], "1", 2) != 0)
			return (INVALID_ARG);
		index--;
	}
	if (are_there_duplicates(argc, argv))
		return (DUPLICATE_ARG);
	return (0);
}