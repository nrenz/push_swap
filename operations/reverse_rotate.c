/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:33:51 by nrenz             #+#    #+#             */
/*   Updated: 2022/05/25 17:50:00 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reverse_rotate(t_push_swap *box)
{
	int	i;
	int	temp;

	i = 0;
	while (box->stack_a[i])
		i--;
	i++;
	temp = box->stack_a[i];
	box->stack_a[0] = box->stack_a[i];
	while (box->stack_a[i])
	{
		box->stack_a[i] = box->stack_a[i + 1];
		i++;
	}
}
