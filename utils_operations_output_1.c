/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_operations_output_1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:11:47 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/15 17:15:31 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_push_swap *push_swap)
{
	ft_swap(&(push_swap->a_list));
	ft_putendl_fd("sa", 1);
}

void	ft_sb(t_push_swap *push_swap)
{
	ft_swap(&(push_swap->b_list));
	ft_putendl_fd("sb", 1);
}

void	ft_ss(t_push_swap *push_swap)
{
	ft_swap(&(push_swap->a_list));
	ft_swap(&(push_swap->b_list));
	ft_putendl_fd("ss", 1);
}

void	ft_pa(t_push_swap *push_swap)
{
	ft_push(&(push_swap->b_list), &(push_swap->a_list));
	ft_putendl_fd("pa", 1);
}

void	ft_pb(t_push_swap *push_swap)
{
	ft_push(&(push_swap->a_list), &(push_swap->b_list));
	ft_putendl_fd("pb", 1);
}
