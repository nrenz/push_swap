/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:19:39 by nrenz             #+#    #+#             */
/*   Updated: 2022/05/25 16:36:56 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate(t_push_swap *box)
{
	int	i;
	int	temp;

	i = 0;
	while (box->stack_a[i])
		i++;
	i--;
	temp = box->stack_a[i];
	box->stack_a[i] = box->stack_a[0];
	while (i > 0)
	{
		box->stack_a[i] = box->stack_a[i - 1];
		i--;
	}
}
