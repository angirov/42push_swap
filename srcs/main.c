#include "push_swap.h"

#include <stdio.h> ///////////////////////////////////////////////////////

int	main(int argc, char **argv)
{
	int	count;
	t_list *link;

	count = 0;
	link = malloc(sizeof(t_list));
	printf("%d\n", argc);
	while (count < argc)
	{
		printf("%s\n", argv[count]);
		link->next = malloc(sizeof(t_list));
		link->content = argv[count];
		count++;
	}
	printf("%ld\n", ft_strlen("123"));
	return 0;
}
