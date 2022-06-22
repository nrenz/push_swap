/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:32:41 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/22 16:29:19 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_b_list(t_push_swap *push_swap)
{
	while (ft_lstsize(push_swap->a_list) > 3)
	{
		if (push_swap->a_list->content == push_swap->min
			|| push_swap->a_list->content == push_swap->med
			|| push_swap->a_list->content == push_swap->max)
			ft_ra(push_swap);
		else
			ft_pb(push_swap);
	}
}

int	ft_lstsize(t_list *lst)
{
	int	length;

	length = 0;
	while (lst)
	{
		lst = lst->next;
		length++;
	}
	return (length);
}

void	ft_final_sort(t_push_swap *push_swap)
{
	t_list	*ptr;
	int		counter;
	int		size;

	ft_find_minmedmax(push_swap->a_list, push_swap);
	ptr = push_swap->a_list;
	counter = 0;
	while (ptr->content != push_swap->min)
	{
		counter++;
		ptr = ptr->next;
	}
	size = ft_lstsize(push_swap->a_list);
	if (counter <= size - counter)
	{
		while (counter-- > 0)
			ft_ra(push_swap);
	}
	else
		while (counter++ < size)
			ft_rra(push_swap);
}

void	ft_sort_list(t_push_swap *push_swap)
{
	if (!ft_is_sorted(push_swap->a_list))
	{
		ft_find_minmedmax(push_swap->a_list, push_swap);
		ft_fill_b_list(push_swap);
		ft_triple_sort(push_swap);
		while (push_swap->b_list)
			ft_transfer_to_a_list(push_swap);
	}
	ft_final_sort(push_swap);
}