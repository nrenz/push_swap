/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_to_a_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:54:51 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/22 16:47:01 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find_best_elem(t_list *list, int *transfer_type)
{
	t_list	*temp_elem;
	int		best_total_score;
	int		best_rank;
	int		best_ttype;

	best_total_score = ft_total_score(list, transfer_type);
	best_rank = list->rank;
	best_ttype = *transfer_type;
	temp_elem = list;
	while (list)
	{
		if (ft_total_score(list, transfer_type) < best_total_score
			|| (ft_total_score(list, transfer_type) == best_total_score
				&& list->rank >= best_rank))
		{
			best_total_score = ft_total_score(list, transfer_type);
			best_rank = list->rank;
			best_ttype = *transfer_type;
		}
		list = list->next;
	}
	*transfer_type = best_ttype;
	while (temp_elem->rank != best_rank)
		temp_elem = temp_elem->next;
	return (temp_elem);
}

int	ft_total_score(t_list *list, int *transfer_type)
{
	int	result;
	int	biggest_rscore;

	result = list->score_b_list;
	*transfer_type = 1;
	if (list->score_a_list >= list->score_b_list)
	{
		result = list->score_a_list;
		*transfer_type = 2;
	}
	biggest_rscore = list->rscore_a_list;
	if (list->rscore_b_list > biggest_rscore)
		biggest_rscore = list->rscore_b_list;
	if (result > biggest_rscore)
	{
		result = biggest_rscore;
		if (list->rscore_b_list > list->rscore_a_list)
			*transfer_type = 3;
		else
			*transfer_type = 4;
	}
	result = ft_total_score2(result, list, transfer_type);
	return (result);
}

int	ft_total_score2(int result, t_list *list, int *transfer_type)
{
	if (list->score_b_list + list->rscore_a_list < result)
	{
		result = list->score_b_list + list->rscore_a_list;
		*transfer_type = 5;
	}
	if (list->rscore_b_list + list->score_a_list < result)
	{
		result = list->rscore_b_list + list->score_a_list;
		*transfer_type = 6;
	}
	return (result);
}

void	ft_process_decision(t_push_swap *push_swap, t_list *elem, int *ttype)
{
	if (*ttype == 1)
	{
		while (elem->score_a_list-- > 0 && elem->score_b_list--)
			ft_rr(push_swap);
		while (elem->score_b_list-- > 0)
			ft_rb(push_swap);
	}
	if (*ttype == 2)
	{
		while (elem->score_b_list-- > 0 && elem->score_a_list--)
			ft_rr(push_swap);
		while (elem->score_a_list-- > 0)
			ft_ra(push_swap);
	}
	if (*ttype == 3)
	{
		while (elem->rscore_a_list-- > 0 && elem->rscore_b_list--)
			ft_rrr(push_swap);
		while (elem->rscore_b_list-- > 0)
			ft_rrb(push_swap);
	}
	if (*ttype > 3)
		ft_process_decision2(push_swap, elem, ttype);
	ft_pa(push_swap);
}

void	ft_process_decision2(t_push_swap *push_swap, t_list *elem, int *ttype)
{
	if (*ttype == 4)
	{
		while (elem->rscore_b_list-- > 0 && elem->rscore_a_list--)
			ft_rrr(push_swap);
		while (elem->rscore_a_list-- > 0)
			ft_rra(push_swap);
	}
	if (*ttype == 5)
	{
		while (elem->score_b_list-- > 0)
			ft_rb(push_swap);
		while (elem->rscore_a_list-- > 0)
			ft_rra(push_swap);
	}
	if (*ttype == 6)
	{
		while (elem->rscore_b_list-- > 0)
			ft_rb(push_swap);
		while (elem->score_a_list-- > 0)
			ft_ra(push_swap);
	}
}
