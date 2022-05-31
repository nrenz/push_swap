/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:37:16 by nrenz             #+#    #+#             */
/*   Updated: 2022/05/31 14:08:57 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	ft_rotate(t_list *box)
{
	t_list	*first;
	t_list	*last;
	t_list	*second_to_last;
	t_list	*temp;

	box = first;
	last = box;
	while (!last->next)
		last = last->next;
	second_to_last = box;
	while (!second_to_last->next->next)
		second_to_last = second_to_last->next;
	temp = ;
	first->next = NULL;
	
}
