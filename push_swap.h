/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:03:21 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/09 16:04:40 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT32_MAX 2147483647
# define INT32_MIN -2147483648

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_push_swap
{
	t_list	*a_list;
	t_list	*b_list;
}	t_push_swap;

t_list	*create_a_list(size_t list_size, char **argv);
t_list	*create_b_list(void);
int		ft_is_digit(int c);
int		ft_atoi(const char *str);
bool	ft_check_error(char **argv);
bool	ft_check_duplicates(char **argv);
bool	ft_check_presort(char **argv);
t_list	*ft_create_new_list(int content);
t_list	*ft_last_list(t_list *lst);
int		ft_list_size(t_list *lst);
void	ft_list_add_back(t_list **lst, t_list *new);
void	ft_swap(t_list **list);
void	ft_rotate(t_list **list);
void	ft_reverse_rotate(t_list **list);
void	ft_push(t_list **src_list, t_list **dst_list);

#endif