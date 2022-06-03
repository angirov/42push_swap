/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:11:44 by vangirov          #+#    #+#             */
/*   Updated: 2022/06/03 19:40:09 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* These are kind of candidates for the bonus part of Libft */

t_list	*ft_lst_penult(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

int	ft_lst_is_sorted(t_list **head)
{
	t_list	*link;

	link = *head;
	while (link && link->next)
	{
		if (ft_value(link) > ft_value(link->next))
			return (0);
		link = link->next;
	}
	return (1);
}

/* A shortcut lst > stack */
int	ft_stack_is_sorted(t_stack *x)
{
	return (ft_lst_is_sorted(x->head));
}

int	ft_lst_num_is_unique(t_list **head, int num)
{
	t_list	*link;

	link = *head;
	while (link && link->next)
	{
		if (ft_value(link) == num)
			return (0);
		link = link->next;
	}
	return (1);
}
