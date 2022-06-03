/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:29:55 by vangirov          #+#    #+#             */
/*   Updated: 2022/06/03 19:38:21 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free_list(t_list **head)
{
	t_list	*link;
	t_list	*tmp;

	link = *head;
	while (link)
	{
		tmp = link->next;
		free(link->content);
		free(link);
		link = tmp;
	}
	return (1);
}

int	ft_free_stacks(t_stacks *stacks)
{
	ft_free_list(stacks->a->head);
	ft_free_list(stacks->b->head);
	free(stacks->a->head);
	free(stacks->b->head);
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	return (1);
}

int	ft_error_exit(t_stacks *stacks)
{
	ft_free_stacks(stacks);
	write(2, "Error\n", 6);
	return (-1);
}
