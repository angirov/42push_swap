/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:24:36 by vangirov          #+#    #+#             */
/*   Updated: 2022/06/03 13:52:36 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_index(t_list *link)
{
	return ((*(t_content *)link->content).index);
}

int	ft_value(t_list *link)
{
	return ((*(t_content *)link->content).value);
}

void	my_print_bi(unsigned int num)
{
	unsigned int i = 1 << 31;

	while (i)
	{
		if ((num & i) == 0)
			printf("0");
		else
			printf("1");
		i = i >> 1;
	}
}

void	my_print_bi_first(unsigned int num, int first)
{
	unsigned int i = 1 << (first - 1);

	while (i)
	{
		if ((num & i) == 0)
			printf("0");
		else
			printf("1");
		i = i >> 1;
	}
}


// ft_free_stacks(stacks);
// for (unsigned int i = 1; i != (i << 31); i = i << 1)
// 	my_print_bi(i);

void	my_print_stack(t_stack *x)
{
	t_list *link;

	link = *x->head;
	while(link)
	{
		printf("%5d\t", ft_value(link));
		printf("[%d]\n", ft_index(link));
		link = link->next;
	}
	printf("============\n");
}

void	my_print_stack_bi(t_stack *x)
{
	t_list *link;

	link = *x->head;
	while(link)
	{
		printf("%5d\t", ft_value(link));
		printf("i%3d = [", ft_index(link));
		my_print_bi_first(ft_index(link), 6);
		printf("]\n");
		link = link->next;
	}
	printf("============\n");
}

void	my_print_both(t_stacks *stacks)
{
	printf("############\nA:\n");
	my_print_stack(stacks->a); ////////////////////////////////////////////////////////////////
	printf("B:\n");
	my_print_stack(stacks->b); ////////////////////////////////////////////////////////////////
}

void	my_print_both_bi(t_stacks *stacks)
{
	printf("############\nA:\n");
	my_print_stack_bi(stacks->a); ////////////////////////////////////////////////////////////////
	printf("B:\n");
	my_print_stack_bi(stacks->b); ////////////////////////////////////////////////////////////////
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int		stack_len;

	if (argc == 1)
		return (0);
	stacks = (t_stacks *)malloc(sizeof(stacks));
	stack_len = ft_read_input(argc, argv, stacks);
	if (stack_len <=0)
		return (ft_error_exit(stacks));
	// my_print_both(stacks); ////////////////////////////////////////////////////////////////
	// printf("pos min = %d\n", ft_lst_pos_min(stacks->a->head));
	// printf("lst size = %d\n", ft_lstsize(*stacks->a->head));
	if (!ft_stack_is_sorted(stacks->a))
	{
		if (stack_len == 2)
			ft_ra(stacks);
		if (stack_len == 3)
			ft_sort_3(stacks);
		if (stack_len >= 4 && stack_len <= 5) 
			ft_sort_4(stacks);
		else
			ft_redix(stacks);
	}
	// if (ft_stack_is_sorted(stacks->a))
	// 	printf("Sorting test OK\n");
	// my_print_both_bi(stacks); ////////////////////////////////////////////////////////////////

	return(0);
}

// https://numbergenerator.org/