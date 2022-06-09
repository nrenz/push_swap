/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:04:34 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/09 16:36:46 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **list)
{
	t_list	*temp;

	temp = *list;
	*list = temp->next;
	temp->next = (*list)->next;
	(*list)->next = temp;
}

void	ft_rotate(t_list **list)
{
	t_list	*last_node;
	t_list	*temp;

	last_node = ft_last_list(*list);
	temp = (*list)->next;
	(*list)->next = NULL;
	last_node->next = *list;
	*list = temp;
}

void	ft_reverse_rotate(t_list **list)
{
	t_list	*second_to_last_node;
	t_list	*last_node;
	t_list	*temp;

	last_node = ft_last_list(*list);
	second_to_last_node = *list;
	while (second_to_last_node->next->next != NULL)
		second_to_last_node = second_to_last_node->next;
	temp = second_to_last_node->next;
	second_to_last_node->next = NULL;
	last_node->next = *list;
	*list = temp;
}

// push first element of src_list to top of dst_list
void	ft_push(t_list **src_list, t_list **dst_list)
{
	t_list	*temp;

	temp = (*src_list)->next;
	(*src_list)->next = *dst_list;
	*dst_list = *src_list;
	*src_list = temp;
}
