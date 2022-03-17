/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:32:42 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/03/17 13:06:02 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		atoi, -- convert ASCII string to integer
** DESCRIPTION
** 		The atoi() function converts the initial portion of the string
** 		pointed to by str to int representation.
** RETURN VALUE
** 		The converted value.
*/

int	ft_atoi(const char *str)
{
	int			sign;
	long int	result;

	sign = 1;
	result = 0;
	while ((*str == ' ') || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (NOT_INTEGER);
		result = (result * 10) + (*str - '0');
		if (result < INT_MIN || result > INT_MAX)
			return (INTEGER_OVERFLOW);
		str++;
	}
	return (result * sign);
}
