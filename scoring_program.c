/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:29:07 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/30 11:40:27 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_score_for_b_list(t_list *list)
{
	int	i;
	int	size;

	size = ft_lstsize(list);
	i = 0;
	while (list)
	{
		list->score_b_list = i;
		if (i == 0)
			list->rscore_b_list = 0;
		else
			list->rscore_b_list = size - i;
		i++;
		list = list->next;
	}
}

void	ft_set_score_for_a_list(t_list *a_list, t_list *b_list, int i, int size)
{
	if (a_list->content > b_list->content
		&& ft_last_list(a_list)->content < b_list->content && i == 0)
	{
		b_list->score_a_list = 0;
		b_list->rscore_a_list = 0;
	}
	else if (a_list->content < b_list->content
		&& a_list->next->content > b_list->content)
	{
		b_list->score_a_list = i + 1;
		b_list->rscore_a_list = size - (i + 1);
	}
}

void	ft_score_for_a_list_(t_list *a_list, t_list *b_list, int i)
{
	t_list	*a_list_head;
	int		size;

	size = ft_lstsize(a_list);
	a_list_head = a_list;
	while (b_list)
	{
		i = 0;
		a_list = a_list_head;
		while (a_list->next)
		{
			ft_set_score_for_a_list(a_list, b_list, i, size);
			a_list = a_list->next;
			i++;
		}
		b_list = b_list->next;
	}
}
