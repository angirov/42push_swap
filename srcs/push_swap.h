/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:47:29 by vangirov          #+#    #+#             */
/*   Updated: 2022/05/23 23:20:02 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h> ///////////////////////////////////////////////////////

// https://www2.hs-fulda.de/~klingebiel/c-stdlib/limits.h.htm
# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	t_list	**head;
} t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
} t_stacks;

typedef	struct s_content
{
	int	value;
	uint	index;
}	t_content;

// ===== READING.C ===== //
int	ft_read_input(int argc, char **argv, t_stacks *stacks);
int	ft_init_stacks(t_stacks *stacks);
int	ft_atoi_good_num(t_list **head, char *str, int *num);
t_list	*ft_lst_new_num(int num);

// ===== INDEXING.C ===== //

void	ft_index_stack(t_stack *stack);
int	ft_new_min(t_list **head, t_list **new_min);

// ===== SORTING.C ===== //
void	ft_sort_3(t_stacks *stacks);
int	ft_lst_pos_min(t_list **head);
void	ft_repeat(void (* opration)(t_stacks *), t_stacks *stacks, int times);
void	ft_empty_b(t_stacks *stacks);
void	ft_sort_4(t_stacks *stacks);

// ===== REDIX.C ===== //
int		ft_nth_byte_is_1(int index, uint n);
void	ft_separate_by_nth_byte(t_stacks *stacks, uint len, uint n);
void	ft_redix(t_stacks *stacks);

// ===== FREEING.C ===== //
int	ft_free_list(t_list **head);
int	ft_free_stacks(t_stacks *stacks);
int	ft_error_exit(t_stacks *stacks);

// ===== LST_FUNCTIONS.C ===== //
t_list	*ft_lst_penult(t_list *lst);
int	ft_lst_num_is_unique(t_list **head, int num);
int	ft_lst_is_sorted(t_list **head);
int	ft_stack_is_sorted(t_stack *x);

// ===== OPERATIONS =====//
void	ft_sa(t_stacks *stacks);
void	ft_sb(t_stacks *stacks);
void	ft_pa(t_stacks *stacks);
void	ft_pb(t_stacks *stacks);
void	ft_ra(t_stacks *stacks);
void	ft_rb(t_stacks *stacks);
void	ft_rr(t_stacks *stacks);
void	ft_rra(t_stacks *stacks);
void	ft_rrb(t_stacks *stacks);
void	ft_rrr(t_stacks *stacks);

// ===== MAIN.C ===== //
int	ft_index(t_list *link);
int	ft_value(t_list *link);
void	my_print_bi(uint num);
void	my_print_bi_first(uint num, int first);
void	my_print_both_bi(t_stacks *stacks);

#endif
