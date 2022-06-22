/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:02:48 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/22 16:50:16 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	ft_print_list_score(t_list *list);

t_list	*create_a_list(size_t list_size, char **argv)
{
	t_list	*first_node;
	t_list	*further_node;
	int		ptr_to_number;
	size_t	i;

	ptr_to_number = ft_atoi(argv[1]);
	first_node = ft_create_new_list(ptr_to_number);
	if (!first_node)
		return (NULL);
	i = 1;
	while (i++ < list_size)
	{
		ptr_to_number = ft_atoi(argv[i]);
		further_node = ft_create_new_list(ptr_to_number);
		if (!further_node)
			return (NULL);
		ft_list_add_back(&first_node, further_node);
	}
	return (first_node);
}

t_list	*create_b_list(void)
{
	t_list	*b_list;

	b_list = NULL;
	return (b_list);
}

int	main(int argc, char **argv)
{
	t_push_swap	*push_swap;

	push_swap = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (ft_check_error(argv) || ft_check_duplicates(argv))
	{
		write(2, "error", 6);
		return (1);
	}
	if (ft_check_presort(argv))
	{
		write(1, "already sorted", 15);
		return (0);
	}
	push_swap->a_list = create_a_list(argc - 1, argv);
	push_swap->b_list = create_b_list();
	if (!push_swap->a_list)
		return (1);
	// dont forget to free allocated stuff
	ft_sort_list(push_swap);
	ft_print_list(push_swap->a_list);
	return (0);
}

void	ft_print_list(t_list *list)
{
	while (list != NULL)
	{
		printf("  %d\n", list->content);
		list = list->next;
	}
}

void	ft_print_list_score(t_list *list)
{
	while (list != NULL)
	{
		printf("	##########\n");
		printf("		%d\n", list->content);
		printf("score_a: %d - rscore_a: %d\n", list->score_a_list, list->rscore_a_list);
		printf("score_b: %d - rscore_b: %d\n", list->score_b_list, list->rscore_b_list);
		printf("	rank: 	%d\n", list->rank);
		printf("	##########\n");
		list = list->next;
	}
}
