/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:19:15 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/29 15:28:58 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two_numbers(t_push_swap *push_swap)
{
	if (push_swap->a_list->content > push_swap->a_list->next->content)
		ft_sa(push_swap);
}
