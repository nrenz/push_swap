/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_operations_output_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:22:52 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/22 16:48:22 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_push_swap *push_swap)
{
	ft_rotate(&(push_swap->a_list));
	ft_putendl_fd("ra", 1);
}

void	ft_rb(t_push_swap *push_swap)
{
	ft_rotate(&(push_swap->b_list));
	ft_putendl_fd("rb", 1);
}

void	ft_rr(t_push_swap *push_swap)
{
	ft_rotate(&(push_swap->a_list));
	ft_rotate(&(push_swap->b_list));
	ft_putendl_fd("rr", 1);
}

void	ft_rra(t_push_swap *push_swap)
{
	ft_reverse_rotate(&(push_swap->a_list));
	ft_putendl_fd("rra", 1);
}

void	ft_rrb(t_push_swap *push_swap)
{
	ft_reverse_rotate(&(push_swap->b_list));
	ft_putendl_fd("rrb", 1);
}
