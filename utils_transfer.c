/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_transfer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:53:23 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/22 16:58:14 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_transfer_to_a_list(t_push_swap *push_swap)
{
	t_list	*best_rank_elem;
	int		ttype;

	ft_score_for_b_list(push_swap->b_list);
	ft_score_for_a_list_(push_swap->a_list, push_swap->b_list, 0);
	best_rank_elem = ft_find_best_elem(push_swap->b_list, &ttype);
	ft_process_decision(push_swap, best_rank_elem, &ttype);
	if (!ft_is_sorted(push_swap->a_list))
	{
		printf("AAAAAH mistake at: %d\n", push_swap->a_list->content);
		exit (1);
	}
}
