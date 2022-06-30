/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:00:24 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/30 11:40:40 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_presort_array(t_list *list, int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (list != NULL)
	{
		array[i++] = list->content;
		list = list->next;
	}
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
	return (array);
}

void	ft_set_index(t_list *list, int *array)
{
	int	i;

	while (list)
	{
		i = 0;
		while (array[i] != list->content)
			i++;
		list->index = i;
		list = list->next;
	}
}

void	ft_find_minmedmax(t_list *list, t_push_swap *push_swap)
{
	int	*array;
	int	size;

	size = ft_lstsize(list);
	array = malloc(sizeof(int) * size);
	if (!array)
		return ;
	array = ft_presort_array(list, array, size);
	push_swap->min = array[0];
	push_swap->med = array[size / 2];
	push_swap->max = array[size - 1];
	ft_set_index(list, array);
	free(array);
}

void	ft_triple_sort(t_push_swap *push_swap)
{
	int	first;
	int	second;
	int	third;

	while (!ft_is_sorted(push_swap->a_list))
	{
		first = (push_swap->a_list->content);
		second = (push_swap->a_list->next->content);
		third = (push_swap->a_list->next->next->content);
		if (first < second && second > third)
			ft_rra(push_swap);
		if (third > first && third > second && first > second)
			ft_sa(push_swap);
		else if (first > third && first > second)
		{
			ft_ra(push_swap);
			if (second > third)
				ft_sa(push_swap);
		}
	}
}

int	ft_is_sorted(t_list *list)
{
	while (list->next)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}
