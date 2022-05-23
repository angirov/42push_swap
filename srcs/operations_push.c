/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:49:34 by vangirov          #+#    #+#             */
/*   Updated: 2022/05/23 21:30:35 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *from, t_stack *to)
{
	t_list	*first_from;

	if (!*from->head)
		return;
	first_from = *from->head;
	if (first_from->next)
		*from->head = first_from->next;	// H > 2
	else
		*from->head = NULL;
	first_from->next = *to->head;
	*to->head = first_from;
}

void	ft_pa(t_stacks *stacks)
{
	ft_push(stacks->a, stacks->b);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stacks *stacks)
{
	ft_push(stacks->b, stacks->a);
	write(1, "pb\n", 3);
}
