#include "push_swap.h"


void	my_print_stack(t_stack *x)
{
	t_list *link;

	link = *x->head;
	while(link)
	{
		printf("%d\n", *(int *)link->content);
		link = link->next;
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
	if (ft_lst_is_sorted(stacks->a->head))
	{
	// 	if (stack_len == 2)
			ft_ra(stacks);
	// 	if (stack_len == 3)
	// 		ft_sort3(stacks);
	// 	if (stack_len == 5)
	// 		ft_sort5(stacks);
	// 	else
	// 		ft_sort0(stacks, stack_len);
	}
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
