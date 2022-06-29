/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:52:37 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/29 14:50:52 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// long long int	check_range_num(long long int nb)
// {
// 	if (nb < INT32_MIN || nb > INT32_MAX)
// 		return (0);
// 	return (1);
// }

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
