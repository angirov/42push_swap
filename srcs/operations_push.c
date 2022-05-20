/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:49:34 by vangirov          #+#    #+#             */
/*   Updated: 2022/05/20 13:59:29 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *from, t_stack *to, char *name_from)
{
	t_list	*first_from;
	
	first_from = *from->head;

	*from->head = first_from->next;;			// H > 2
	first_from->next = *to->head;
	*to->head = first_from;

	printf(">>> p%s\n", name_from);
}

void	ft_pa(t_stacks *stacks)
{
	ft_push(stacks->a, stacks->b, "a");
}

void	ft_pb(t_stacks *stacks)
{
	ft_push(stacks->b, stacks->a, "b");
}
