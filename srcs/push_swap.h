/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:47:29 by vangirov          #+#    #+#             */
/*   Updated: 2022/05/20 10:32:45 by vangirov         ###   ########.fr       */
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

// ===== READING.C ===== //
int	ft_read_input(int argc, char **argv, t_stacks *stacks);
int	ft_atoi_good_num(t_list **head, char *str, int *num);
t_list *ft_lst_new_num(int num);
int	ft_is_unique(t_list **head, int num);

// ===== FREEING.C ===== //
int	ft_free_list(t_list **head);
int	ft_free_stacks(t_stacks *stacks);
int	ft_error_exit(t_stacks *stacks);

#endif