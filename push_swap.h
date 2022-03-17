/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:47:46 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/03/17 18:51:19 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define UNSPECIFIED_ARG 1
# define INVALID_ARG 1
# define DUPLICATE_ARG 1
# define PARSING_ERROR 1

int	parse_arguments(int argc, char *argv[]);

#endif