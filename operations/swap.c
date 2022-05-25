/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:51:37 by nrenz             #+#    #+#             */
/*   Updated: 2022/05/25 16:00:43 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_push_swap *box)
{
	int	temp;

	temp = box->stack_a[0];
	box->stack_a[0] = box->stack_a[1];
	box->stack_a[1] = temp;
}
