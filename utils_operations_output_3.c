/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_operations_output_3.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:09:32 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/15 16:45:03 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_push_swap *push_swap)
{
	ft_reverse_rotate(&(push_swap->a_list));
	ft_reverse_rotate(&(push_swap->b_list));
	ft_putendl_fd("rrr", 1);
}
