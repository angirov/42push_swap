/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:49:34 by vangirov          #+#    #+#             */
/*   Updated: 2022/05/20 14:34:06 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_stack *x)
{
	t_list	*first;
	t_list	*penult;

	first = *x->head;
	penult = ft_lst_penult(first);
	*x->head = ft_lstlast(first);
	(*x->head)->next = first;
	penult->next = NULL;
}

void	ft_rra(t_stacks *stacks)
{
	ft_rev_rotate(stacks->a);
}

void	ft_rrb(t_stacks *stacks)
{
	ft_rev_rotate(stacks->b);
}

void	ft_rrr(t_stacks *stacks)
{
	ft_rev_rotate(stacks->a);
	ft_rev_rotate(stacks->b);
	
}
