/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:02:48 by nrenz             #+#    #+#             */
/*   Updated: 2022/05/31 13:11:36 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_error_chek(char **argv)
{
	while (**argv)
	{
		if ((ft_atoi(*argv) > INT32_MAX) || (ft_atoi(*argv) < INT32_MIN))
			return (1);
		while (**argv)
		{
			if (!ft_digit(**argv))
				return (1);
			*argv++;
		}
	}
}

t_list	*a_list(size_t list_size, char **argv)
{
	t_list	*a_box;
	t_list	*node;
	int		i;

	if (!a_box)
		return (NULL);
	a_box = ft_lstnew(ft_atoi(argv[1]));
	i = 0;
	while (i++ < list_size)
	{
		node = ft_lstnew(ft_atoi(argv[i]));
		if (!node)
			return (NULL);
		ft_lstadd_back(&a_box, node);
	}
	return (a_box);
}

t_list	*b_list(size_t list_size, char **argv)
{
	t_list	*b_box;

	if (!b_list)
		return (NULL);
	b_box = ft_lstnew(NULL);
}
