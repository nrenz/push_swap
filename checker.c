/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:50:04 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/29 10:04:52 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_command_check(char line)
{
	if (line = "sa")
		sa;
	else if (line = "sb")
		sb;
	else if (line = "pa")
		pa;
	else if (line = "pb")
		pb;
	else if (line = "ra")
		ra;
	else if (line = "rb")
		rb;
	else if (line = "rra")
		rra;
	else if (line = "rrb")
		rrb;
	else
		(1);
	if (ft_sort)
		write (1, "ok", 1);
	else
		write (1, "ko", 1);
}
 */
char	*ft_checker(char *line)
{
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		ft_command_check();
	}
}
