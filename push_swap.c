/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:51:01 by nrenz             #+#    #+#             */
/*   Updated: 2022/05/25 17:49:29 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	int			n;
	t_push_swap	*box; // pointer dann ->; ohne pointer .

	box = malloc(sizeof(t_push_swap));
	box->stack_a = malloc(sizeof(t_push_swap));
	box->stack_b = malloc(sizeof(t_push_swap));
	i = 1;
	n = 0;
	while (argv[i])
	{
		box->stack_a[n] = ft_atoi(argv[i]); // die Zahlen werden im Stack_a abgespeichert
		i++;
		n++;
	}
	ft_reverse_rotate(box);
	printf("%d\n", box->stack_a[4]);
}
