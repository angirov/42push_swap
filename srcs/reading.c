/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:24:36 by vangirov          #+#    #+#             */
/*   Updated: 2022/06/03 19:50:21 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_long_atoi(const char *nptr)
{
	long	num;
	int		minus;

	num = 0;
	minus = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		minus = 1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
		num = num * 10 + (*nptr++ - '0');
	if (minus)
		num *= -1;
	return (num);
}

int	ft_read_input(int argc, char **argv, t_stacks *stacks)
{
	int	count;
	int	num;

	ft_init_stacks(stacks);
	count = 1;
	while (count < argc)
	{
		if (!ft_atoi_good_num(stacks->a->head, argv[count], &num))
			return (-1);
		if (count == 1)
			*stacks->a->head = ft_lst_new_num(num);
		else
			ft_lstadd_back(stacks->a->head, ft_lst_new_num(num));
		count++;
		if (!ft_lst_num_is_unique(stacks->a->head, num))
			return (-1);
	}
	return (argc - 1);
}

int	ft_init_stacks(t_stacks *stacks)
{
	stacks->a = (t_stack *)malloc(sizeof(t_stack));
	stacks->a->head = (t_list **)malloc(sizeof(t_list *));
	stacks->b = (t_stack *)malloc(sizeof(t_stack));
	stacks->b->head = (t_list **)malloc(sizeof(t_list *));
	*stacks->a->head = NULL;
	*stacks->b->head = NULL;
	return (1);
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
		if (ft_strlen(str) > 1 && n == 0 && str[0] == '-')
			n++;
		else if (!ft_isdigit(str[n++]))
			return (0);
	}
	n = ft_long_atoi(str);
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	*num = n + &head - &head;
	return (1);
}

t_list	*ft_lst_new_num(int num)
{
	t_content	*content;

	content = (t_content *)malloc(sizeof(content));
	content->value = num;
	content->index = 0;
	return (ft_lstnew(content));
}

// t_list *ft_lst_new_num(int num)
// {
// 	int *ptr;

// 	ptr = (int *)malloc(sizeof(int));
// 	*ptr = num;
// 	return ft_lstnew(ptr);
// }