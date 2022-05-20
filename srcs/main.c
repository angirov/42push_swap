#include "push_swap.h"

int	ft_index(t_list *link)
{
	return ((*(t_content *)link->content).index);
}

int	ft_value(t_list *link)
{
	return ((*(t_content *)link->content).value);
}

int	ft_new_min(t_list **head, t_list **new_min)
{
	t_list	*link;
	t_list	*lesser;
	int		min;

	link = *head;
	lesser = NULL;
	min = INT_MAX;
	while(link)
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
	t_list	**new_min;
	int		i;

	new_min = (t_list **)malloc(sizeof(t_list *));
	i = 1;
	while(ft_new_min(stack->head, new_min))
		((t_content *)(*new_min)->content)->index = i++;
	free(new_min);
}

void	my_print_stack(t_stack *x)
{
	t_list *link;

	link = *x->head;
	while(link)
	{
		printf("%d ", ft_value(link));
		printf("[%d]\n", ft_index(link));
		link = link->next;
	}
	printf("=====\n");
}

void	my_print_both(t_stacks *stacks)
{
	printf("##################\nA:\n");
	my_print_stack(stacks->a); ////////////////////////////////////////////////////////////////
	printf("B:\n");
	my_print_stack(stacks->b); ////////////////////////////////////////////////////////////////
}

void	ft_sort_3(t_stacks *stacks)
{
	if (ft_index(*stacks->a->head) == 1)
	{
		ft_rra(stacks);
		ft_sa(stacks);
	}
	else if (ft_index(*stacks->a->head) == 2)
		if (ft_index((*stacks->a->head)->next) == 1)
			ft_sa(stacks);
		else
			ft_rra(stacks);
	else
		if (ft_index((*stacks->a->head)->next) == 1)
			ft_ra(stacks);
		else
		{
			ft_sa(stacks);
			ft_rra(stacks);
		}
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

	my_print_both(stacks); ////////////////////////////////////////////////////////////////
	ft_index_stack(stacks->a);
	if (!ft_stack_is_sorted(stacks->a))
	{
		if (stack_len == 2)
			ft_ra(stacks);
		if (stack_len == 3)
			ft_sort_3(stacks);
	// 	if (stack_len == 5)
	// 		ft_sort5(stacks);
	// 	else
	// 		ft_sort0(stacks, stack_len);
	}
	my_print_both(stacks); ////////////////////////////////////////////////////////////////
	ft_free_stacks(stacks);
	return(0);
}










////////////////////////////////////////
// #include <stdio.h> ///////////////////////////////////////////////////////
// int	main(int argc, char **argv)
// {
// 	int	count;
// 	t_list *link;

// 	count = 0;
// 	link = malloc(sizeof(t_list));
// 	printf("%d\n", argc);
// 	while (count < argc)
// 	{
// 		printf("%s\n", argv[count]);
// 		link->next = malloc(sizeof(t_list));
// 		link->content = argv[count];
// 		count++;
// 	}
// 	printf("Tokum of argv[1]: %d\n", ft_toknum(argv[1], ' '));
// 	return 0;
// }
