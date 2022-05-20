/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:49:34 by vangirov          #+#    #+#             */
/*   Updated: 2022/05/20 23:20:42 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *x)
{
	t_list	*first;
	t_list	*second;
	
	first = *x->head;
	second = first->next;

	first->next = second->next;	// 1 > 3
	second->next = *x->head;	// 2 > 1
	*x->head = second;			// H > 2
}

void	ft_sa(t_stacks *stacks)
{
	ft_swap(stacks->a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_stacks *stacks)
{
	ft_swap(stacks->b);
	write(1, "sa\n", 3);
}
