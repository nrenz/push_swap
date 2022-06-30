/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:03:21 by nrenz             #+#    #+#             */
/*   Updated: 2022/06/30 11:40:07 by nrenz            ###   ########.fr       */
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
	int				score_a_list;
	int				rscore_a_list;
	int				score_b_list;
	int				rscore_b_list;
	int				index;
}					t_list;

typedef struct s_push_swap
{
	t_list	*a_list;
	t_list	*b_list;
	int		min;
	int		med;
	int		max;
}			t_push_swap;

//create lists, fill, presort, sort
t_list			*create_a_list(size_t list_size, char **argv);
t_list			*create_b_list(void);
void			ft_fill_b_list(t_push_swap *push_swap);
int				ft_is_digit(int c);
int				ft_check_args(int argc);
long long int	ft_atoi(const char *str);
bool			ft_check_error(char **argv);
bool			ft_check_duplicates(char **argv);
bool			ft_check_presort(char **argv);
t_list			*ft_create_new_list(int content);
t_list			*ft_last_list(t_list *lst);
int				ft_lstsize(t_list *lst);
void			ft_list_add_back(t_list **lst, t_list *new);
void			ft_swap(t_list **list);
void			ft_rotate(t_list **list);
void			ft_reverse_rotate(t_list **list);
void			ft_push(t_list **src_list, t_list **dst_list);
void			ft_set_index(t_list *list, int *array);
void			ft_find_minmedmax(t_list *list, t_push_swap *push_swap);
void			ft_putendl_fd(char *s, int fd);
void			ft_sort_two_numbers(t_push_swap *push_swap);
void			ft_triple_sort(t_push_swap *push_swap);

// list operations
void			ft_sa(t_push_swap *push_swap);
void			ft_sb(t_push_swap *push_swap);
void			ft_ss(t_push_swap *push_swap);
void			ft_pa(t_push_swap *push_swap);
void			ft_pb(t_push_swap *push_swap);
void			ft_ra(t_push_swap *push_swap);
void			ft_rb(t_push_swap *push_swap);
void			ft_rr(t_push_swap *push_swap);
void			ft_rra(t_push_swap *push_swap);
void			ft_rrb(t_push_swap *push_swap);
void			ft_rrr(t_push_swap *push_swap);
int				ft_is_sorted(t_list *list);

// ranking, sorting, decision making
void			ft_transfer_to_a_list(t_push_swap *push_swap);
void			ft_score_for_b_list(t_list *list);
void			ft_score_for_a_list_(t_list *a_list, t_list *b_list, int i);
t_list			*ft_find_best_elem(t_list *list, int *transfer_type);
int				ft_total_score(t_list *list, int *transfer_type);
int				ft_total_score2(int result, t_list *list, int *transfer_type);
void			ft_prepare_lists(t_push_swap *push_swap, t_list *elem,
					int *ttype);
void			ft_prepare_lists2(t_push_swap *push_swap, t_list *elem,
					int *ttype);
void			ft_sort_list(t_push_swap *push_swap);
void			ft_final_sort(t_push_swap *push_swap);

#endif