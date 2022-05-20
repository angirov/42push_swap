/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:11:44 by vangirov          #+#    #+#             */
/*   Updated: 2022/05/20 14:37:08 by vangirov         ###   ########.fr       */
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
		if (*(int *)link->content > *(int *)(link->next)->content)
			return (0);
		link = link->next;
	}
	return (1);
}

int	ft_lst_num_is_unique(t_list **head, int num)
{
	t_list	*link;
	// int		same;

	link = *head;
	while(link && link->next)
	{
		// printf("Compare %d and %d\n", *(int *)link->content, num);
		if (*(int *)link->content == num)\
			// printf(">>> SAME !!!\n");
			return (0);
		link = link->next;
	}
	// printf("==============================\n");
	return (1);
}

t_list *ft_lst_new_num(int num)
{
	int *ptr;

	ptr = (int *)malloc(sizeof(int));
	*ptr = num;
	return ft_lstnew(ptr);
}
