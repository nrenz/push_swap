/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_create_lists.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:58:14 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/27 16:55:22 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	long	number;
	long	sign;
	int		i;

	number = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		number = number * 10 + (str[i++] - '0');
	return ((int)sign * number);
}

// erstelle neue Liste, dafür gebe Speicherpltz frei und initialisziere alle Werte für die Listen-Score zu -1,
// damit die Variablen vorgefüllt sind und kein Random-Wert automatisch den Variablen zugewiesen wird.
t_list	*ft_create_new_list(int content)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	newlist->content = content;
	newlist->next = NULL;
	newlist->score_a_list = -1;
	newlist->rscore_a_list = -1;
	newlist->score_b_list = -1;
	newlist->rscore_b_list = -1;
	newlist->index = -1;
	return (newlist);
}

t_list	*ft_last_list(t_list *list)
{
	if (!list)
		return (list);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	ft_list_add_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_last_list(*lst);
		last->next = new;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
	write(fd, "\n", 1);
}
