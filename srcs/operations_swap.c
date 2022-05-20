/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:49:34 by vangirov          #+#    #+#             */
/*   Updated: 2022/05/20 13:43:35 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *x, char *name)
{
	t_list	*first;
	t_list	*second;
	
	first = *x->head;
	second = first->next;

	first->next = second->next;	// 1 > 3
	second->next = *x->head;	// 2 > 1
	*x->head = second;			// H > 2

	printf(">>> s%s\n", name);
}

void	ft_sa(t_stacks *stacks)
{
	ft_swap(stacks->a, "a");
}

void	ft_sb(t_stacks *stacks)
{
	ft_swap(stacks->b, "b");
}
