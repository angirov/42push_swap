/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:25:37 by vangirov          #+#    #+#             */
/*   Updated: 2022/06/03 19:50:52 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nth_byte_is_1(int index, unsigned int n)
{
	return ((index & (1 << n)) != 0);
}

void	ft_separate(t_stacks *stacks, unsigned int len, unsigned int n)
{
	while (len-- > 0)
	{
		if (ft_nth_byte_is_1(ft_index(*stacks->a->head), n))
			ft_ra(stacks);
		else
			ft_pb(stacks);
	}
}

void	ft_redix(t_stacks *stacks)
{
	unsigned int	len;
	unsigned int	n;

	ft_index_stack(stacks->a);
	len = ft_lstsize(*stacks->a->head);
	n = 0;
	while (!ft_stack_is_sorted(stacks->a) && n < 32)
	{
		ft_separate(stacks, len, n++);
		ft_empty_b(stacks);
	}
}
