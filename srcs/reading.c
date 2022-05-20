/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:24:36 by vangirov          #+#    #+#             */
/*   Updated: 2022/05/20 10:27:17 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_read_input(int argc, char **argv, t_stacks *stacks)
{
	int	count;
	int	num;

	count = 1;
	stacks->a = (t_stack *)malloc(sizeof(t_stack));
	stacks->a->head = (t_list **)malloc(sizeof(t_list *));
	stacks->b = (t_stack *)malloc(sizeof(t_stack));
	stacks->b->head = (t_list **)malloc(sizeof(t_list *));
	while (count < argc)
	{
		if (!ft_atoi_good_num(stacks->a->head, argv[count], &num))
			return (-1);
		if (count == 1)
			*stacks->a->head = ft_lst_new_num(num);
		else
			ft_lstadd_back(stacks->a->head, ft_lst_new_num(num));
		count++;
		if (!ft_is_unique(stacks->a->head, num))
			return (-1);
	}
	return(argc - 1);
}

/*
	This function checks if the string of ARGV:
	- consists of digits only of digits, optional '-' in front is OK
	- ft_atoi the string
	- check if within the limits of int
*/
int	ft_atoi_good_num(t_list **head, char *str, int *num)
{
	long	n;

	n = 0;
	while (str[n])
	{
		if (n == 0 && str[0] == '-')
			n++;
		else if (!ft_isdigit(str[n++]))
			return (0);
	}
	n = ft_atoi(str);
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	*num = n + &head - &head;
	return(1);
}

t_list *ft_lst_new_num(int num)
{
	int *ptr;

	ptr = (int *)malloc(sizeof(int));
	*ptr = num;
	return ft_lstnew(ptr);
}

int	ft_is_unique(t_list **head, int num)
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

// int	ft_is_unique(t_list **head)
// {
// 	t_list	*link0;
// 	t_list	*link1;
// 	// int		same;

// 	link0 = *head;
// 	while(link0)
// 	{
// 		link1 = *head;
// 		while(link1)
// 		{
// 			printf("Compare %d and %d\n", *(int *)link0->content, *(int *)link1->content);
// 			link1 = link1->next;
// 			if (link1)
// 				printf("new link1 = %d\n", *(int *)link1->content);
// 		}
// 		link0 = link0->next;
// 	}
// 	printf("==============================\n");
// 	return (1);
// }
