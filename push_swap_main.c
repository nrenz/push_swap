/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:02:48 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/29 12:35:58 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_list *list)
{
	while (list != NULL)
	{
		printf ("%d\n", list->content);
		list = list->next;
	}
}

void	ft_free_lists(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_push_swap	*push_swap;

	if (ft_check_error(argv) || ft_check_duplicates(argv) || ft_check_args(argc))
	{
		write(2, "Error", 6);
		return (1);
	}
	if (ft_check_presort(argv))
	{
		write(1, "Already sorted", 15);
		return (0);
	}
	push_swap = (t_push_swap *)malloc(sizeof(t_push_swap));
	push_swap->a_list = create_a_list(argc - 1, argv);
	// ft_print_list(push_swap->a_list);
	push_swap->b_list = create_b_list();
	if (!push_swap->a_list)
	{
		free(push_swap);
		return (1);
	}
	ft_sort_list(push_swap);
	// ft_print_index(push_swap->a_list);
	// ft_print_list_score(push_swap->a_list);
	// ft_print_list_score(push_swap->b_list);
	ft_print_list(push_swap->a_list);
	ft_free_lists(push_swap->a_list);
	ft_free_lists(push_swap->b_list);
	free(push_swap);
	return (0);
}

// void	ft_print_index(t_list *list)
// {
// 	while (list != NULL)
// 	{
// 		printf("%d\n", list->index);
// 		list = list->next;
// 	}
// }

// void	ft_print_list_score(t_list *list)
// {
// 	while(list != NULL)
// 	{
// 		printf("	##########\n");
// 		printf("		%d\n", list->content);
// 		printf("score_a: %d - rscore_a: %d\n", list->score_a_list, list->rscore_a_list);
// 		printf("score_b: %d - rscore_b: %d\n", list->score_b_list, list->rscore_b_list);
// 		printf("	index: 	%d\n", list->index);
// 		printf("	##########\n");
// 		list = list->next;
// 	}
// }
