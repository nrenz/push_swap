/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:09:51 by nrenz             #+#    #+#             */
/*   Updated: 2022/05/31 14:01:29 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_swap(t_list *box)
{
	t_list	*temp_a;

	if (!box || !box->next)
		return (NULL);
	temp_a = box;
	box = box->next;
	temp_a->next = box->next;
	box->next = temp_a;
	return (box);
}
