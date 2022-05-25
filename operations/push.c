/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:03:02 by nrenz             #+#    #+#             */
/*   Updated: 2022/05/25 16:27:17 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_push_swap *box)
{
	int	temp;
	int	i;

	temp = box->stack_b[0];
	box->stack_b[0] = box->stack_a[0];
	i = 0;
	while (box->stack_a[i])
	{
		box->stack_a[i] = box->stack_a[i + 1];
		i++;
	}
}
