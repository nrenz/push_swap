/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:09:22 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/29 16:57:14 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_check_args(int argc)
{
	if (argc < 2)
		return (1);
	else
		return (0);
}

bool	ft_check_error(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' && argv[i][j + 1])
			j++;
		while (argv[i][j])
		{
			if (!ft_is_digit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

bool	ft_check_duplicates(char **argv)
{
	int	i;
	int	n;

	i = 1;
	while (argv[i])
	{
		n = i + 1;
		while (argv[n])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[n]))
				return (1);
			n++;
		}
		i++;
	}
	return (0);
}

bool	ft_check_presort(char **argv)
{
	int	i;

	i = 1;
	while (argv[i + 1])
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
