/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_transfer_to_a_list.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:29:07 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/27 12:26:51 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
score die Anzahl an operationen um das element nach oben zu bekommen
wenn die zahl bereits ganz oben steht und bereit ist in die liste a gepusht zu werden
ann hat sie einen scoren = 0 und rscore ist authomatisch auch gleich 0 rscore = 0
jedesd element bekommt einen score zeile 30
zeile 32-35 bedeitet, wenn die zhl an der richtigen stelle steht, dann hat es austomatisch beide scores 0
und einene rscore zeile 35-36
*/
void	ft_score_for_b_list(t_list *list)
{
	int	i;
	int	size;

	size = ft_lstsize(list);
	i = 0;
	while (list)
	{
		list->score_b_list = i;
		if (i == 0)
			list->rscore_b_list = 0;
		else
			list->rscore_b_list = size - i;
		i++;
		list = list->next;
	}
}

/*
zeile 47-52: hier wird der fall beschrieben, wenn das richtige element in der a-list
an der richtigen stelle sthet, dann bekommt es utomtisch den score undrscore-wetr 0 zugewiesen
else if: wenn das b-list-element zweischen dem ersten und zweiten a-list-element kommen soll
soll die a-liste entweder einemal nach vorne gedereht werden
oder size - (i + 1) => 4 mal nach unten gedreht werden
*/
void	ft_set_score_for_a_list(t_list *a_list, t_list *b_list, int i, int size)
{
	if (a_list->content > b_list->content
		&& ft_last_list(a_list)->content < b_list->content && i == 0)
	{
		b_list->score_a_list = 0;
		b_list->rscore_a_list = 0;
	}
	else if (a_list->content < b_list->content
		&& a_list->next->content > b_list->content)
	{
		b_list->score_a_list = i + 1;
		b_list->rscore_a_list = size - (i + 1);
	}
}

/*
zeile 67 pointer wird auf anfang der a-liste gesetzt
dann gehen wir mit dem ersten element der b-list die a-list durch
while-loop in zeile 70 bedeutet, nach jeden element b-list kommen n den anfang der a-list
*/
void	ft_score_for_a_list_(t_list *a_list, t_list *b_list, int i)
{
	t_list	*a_list_head;
	int		size;

	size = ft_lstsize(a_list);
	a_list_head = a_list;
	while (b_list)
	{
		i = 0;
		a_list = a_list_head;
		while (a_list->next)
		{
			ft_set_score_for_a_list(a_list, b_list, i, size);
			a_list = a_list->next;
			i++;
		}
		b_list = b_list->next;
	}
}
