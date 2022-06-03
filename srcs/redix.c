/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:25:37 by vangirov          #+#    #+#             */
/*   Updated: 2022/06/03 14:14:32 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nth_byte_is_1(int index, unsigned int n)
{
	return ((index & (1 << n)) != 0);
}

void	ft_separate_by_nth_byte(t_stacks *stacks, unsigned int len, unsigned int n)
{
	while (len-- > 0)
	{
		// printf("%3d ", ft_value(*stacks->a->head));
		// my_print_bi_first(ft_index(*stacks->a->head), 6);
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
		ft_separate_by_nth_byte(stacks, len, n++);
		// my_print_both_bi(stacks); ////////////////////////////////////////////////////////////////
		ft_empty_b(stacks);
	}
}