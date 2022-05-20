#include "push_swap.h"

int	ft_index(t_list *link)
{
	return ((*(t_content *)link->content).index);
}

int	ft_value(t_list *link)
{
	return ((*(t_content *)link->content).value);
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
	printf("A:\n");
	my_print_stack(stacks->a); ////////////////////////////////////////////////////////////////
	printf("B:\n");
	my_print_stack(stacks->b); ////////////////////////////////////////////////////////////////
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
	if (!ft_stack_is_sorted(stacks->a))
	{
		if (stack_len == 2)
			ft_ra(stacks);
	// 	if (stack_len == 3)
	// 		ft_sort3(stacks);
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
