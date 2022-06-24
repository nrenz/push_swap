/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_to_a_list2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:53:23 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/24 12:33:09 by nrenz            ###   ########.fr       */
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
/* 	ft_print_list(push_swap->a_list);
	printf("____a\n");
	ft_print_list(push_swap->b_list);
	printf("____b\n");
	ft_print_list_score(push_swap->b_list); */
	// printf("transferring element rank: %d\n", best_rank_elem->rank);
	ft_process_decision(push_swap, best_rank_elem, &ttype);
}
