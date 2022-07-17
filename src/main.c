#include "push_swap.h"

void reset () {
  printf("\033[0m");
}

void	print_stack(t_list *start_a)
{
	printf("\033[0;36m\n\t-----------START---------\n");
	while (start_a)
	{
		printf("\033[1;33m\t|\tStack A[%d]\t|\n", start_a->n);
		start_a = start_a->next;
	}
	printf("\033[0;36m\t-----------END-----------\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_list	*a;
	t_list	*b;
	char	**test;

	stack = malloc(sizeof(t_stack));
	a = malloc(sizeof(*a));
	b = NULL;
	stack->a = a;
	stack->b = b;
	valid_check(argv);
	test = valid_args(argv, argc);
	fill_stack(stack, test);
	//print_stack(stack->a);
	push_swap(stack);
	return (0);
}
