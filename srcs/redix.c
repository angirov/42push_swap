/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:25:37 by vangirov          #+#    #+#             */
/*   Updated: 2022/05/23 23:23:05 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nth_byte_is_1(int index, uint n)
{
	return ((index & (1 << n)) != 0);
}

void	ft_separate_by_nth_byte(t_stacks *stacks, uint len, uint n)
{
	while (len-- > 0)
	{
		// printf("%3d ", ft_value(*stacks->a->head));
		// my_print_bi_first(ft_index(*stacks->a->head), 6);
		if (ft_nth_byte_is_1(ft_index(*stacks->a->head), n))
			ft_ra(stacks);
		else
			ft_pa(stacks);
	}
}

void	ft_redix(t_stacks *stacks)
{
	uint	len;
	uint	n;

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