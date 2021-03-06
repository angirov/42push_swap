/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:23:37 by vangirov          #+#    #+#             */
/*   Updated: 2022/06/03 19:54:51 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stacks *stacks)
{
	if (ft_stack_is_sorted(stacks->a))
		return ;
	ft_index_stack(stacks->a);
	if (ft_index(*stacks->a->head) == 1)
	{
		ft_rra(stacks);
		ft_sa(stacks);
	}
	else if (ft_index(*stacks->a->head) == 2)
	{
		if (ft_index((*stacks->a->head)->next) == 1)
			ft_sa(stacks);
		else
			ft_rra(stacks);
	}
	else
	{
		if (ft_index((*stacks->a->head)->next) == 1)
			ft_ra(stacks);
		else
		{
			ft_sa(stacks);
			ft_rra(stacks);
		}
	}
}

int	ft_lst_pos_min(t_list **head)
{
	t_list	*link;
	int		pos;
	int		min_pos;
	int		min_val;

	link = *head;
	pos = 1;
	min_pos = 1;
	min_val = INT_MAX;
	while (link)
	{
		if (ft_value(link) < min_val)
		{
			min_val = ft_value(link);
			min_pos = pos;
		}
		link = link->next;
		pos++;
	}
	return (min_pos);
}

void	ft_repeat(void (*operation)(t_stacks *), t_stacks *stacks, int times)
{
	while (times-- > 0)
		operation(stacks);
}

void	ft_empty_b(t_stacks *stacks)
{
	while (*stacks->b->head)
		ft_pa(stacks);
}

void	ft_sort_4(t_stacks *stacks)
{
	int	min_pos;

	while (ft_lstsize(*stacks->a->head) > 3)
	{
		min_pos = ft_lst_pos_min(stacks->a->head);
		if (ft_lstsize(*stacks->a->head) / 2 + 1 >= min_pos)
			ft_repeat(&ft_ra, stacks, min_pos - 1);
		else
			ft_repeat(&ft_rra, stacks, \
				ft_lstsize(*stacks->a->head) - min_pos + 1);
		ft_pb(stacks);
	}
	ft_sort_3(stacks);
	ft_empty_b(stacks);
}
