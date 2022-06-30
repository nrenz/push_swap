/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:02:48 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/30 17:17:42 by nrenz            ###   ########.fr       */
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

void	ft_check_all_erros(char **argv)
{
	if (ft_check_error(argv) || ft_check_duplicates(argv))
		write(2, "Error", 6);
}

int	main(int argc, char **argv)
{
	t_push_swap	*push_swap;

	if (argc < 2)
		return (1);
	ft_check_all_erros(argv);
	if (ft_check_presort(argv))
		return (0);
	push_swap = (t_push_swap *)malloc(sizeof(t_push_swap));
	push_swap->a_list = create_a_list(argc - 1, argv);
	push_swap->b_list = create_b_list();
	if (!push_swap->a_list)
	{
		free(push_swap);
		return (1);
	}
	if (argc == 3)
		ft_sort_two_numbers(push_swap);
	ft_sort_list(push_swap);
	ft_free_lists(push_swap->a_list);
	ft_free_lists(push_swap->b_list);
	free(push_swap);
	return (0);
}
