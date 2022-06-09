/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:02:48 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/09 17:33:00 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_list(t_list *list);

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
	int		i;
	t_list	*a_list;
	t_list	*b_list;
	// char	**split_array;
	// if (argc == 2)
	// 	split_array = ft_split(argv[1], ' ');
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
	a_list = create_a_list(argc - 1, argv);
	b_list = create_b_list();
	if (!a_list)
		return (1);
	i = 0;
	printf("list a:\n");
	ft_print_list(a_list);
	printf("list b:\n");
	printf("\n");
	ft_print_list(b_list);
	printf("\n");
	ft_push(&a_list, &b_list);
	ft_push(&a_list, &b_list);
	ft_push(&a_list, &b_list);
	ft_swap(&a_list);
	ft_push(&b_list, &a_list);
	ft_rotate(&a_list);
	ft_rotate(&a_list);
	ft_reverse_rotate(&a_list);
	printf("\n");
	printf("list a:\n");
	ft_print_list(a_list);
	printf("list b:\n");
	ft_print_list(b_list);
	printf("\noperations: pb, pb, pb, sa, pa, ra, ra, rra\n");
	// dont forget to free allocated stuff
	return (0);
}

static void	ft_print_list(t_list *list)
{
	while (list != NULL)
	{
		printf("  %d\n", list->content);
		list = list->next;
	}
}
