/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:49:34 by vangirov          #+#    #+#             */
/*   Updated: 2022/06/03 19:42:20 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *x)
{
	t_list	*first;

	first = *x->head;
	*x->head = first->next;
	ft_lstlast(first)->next = first;
	first->next = NULL;
}

void	ft_ra(t_stacks *stacks)
{
	ft_rotate(stacks->a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stacks *stacks)
{
	ft_rotate(stacks->b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_stacks *stacks)
{
	ft_rotate(stacks->a);
	ft_rotate(stacks->b);
	write(1, "rr\n", 3);
}
