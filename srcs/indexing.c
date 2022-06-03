/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:22:20 by vangirov          #+#    #+#             */
/*   Updated: 2022/06/03 19:38:56 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_new_min(t_list **head, t_list **new_min)
{
	t_list	*link;
	t_list	*lesser;
	int		min;

	link = *head;
	lesser = NULL;
	min = INT_MAX;
	while (link)
	{
		if (ft_value(link) < min && !ft_index(link))
		{
			lesser = link;
			min = ft_value(lesser);
		}
		link = link->next;
	}
	if (lesser)
	{
		*new_min = lesser;
		return (1);
	}
	return (0);
}

void	ft_index_stack(t_stack *stack)
{
	t_list			**new_min;
	unsigned int	i;

	new_min = (t_list **)malloc(sizeof(t_list *));
	i = 1;
	while (ft_new_min(stack->head, new_min))
		((t_content *)(*new_min)->content)->index = i++;
	free(new_min);
}
