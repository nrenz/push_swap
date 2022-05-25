/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:01:03 by nrenz             #+#    #+#             */
/*   Updated: 2022/05/25 17:48:06 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_push_swap
{
	int	*stack_a;
	int	*stack_b;
} t_push_swap;

int	ft_atoi(const char *str);
void	ft_swap(t_push_swap *box);
void	ft_push(t_push_swap *box);
void	ft_rotate(t_push_swap *box);
void	ft_reverse_rotate(t_push_swap *box);

#endif