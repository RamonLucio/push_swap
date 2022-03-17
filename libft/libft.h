/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:31:27 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/03/17 18:54:17 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define INTEGER_OVERFLOW 1
# define NOT_INTEGER 1

int	ft_atoi(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif