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

int main(int argc, char **argv)
{
	// //fill_list(&stack->a, ft_atoi(argv[1]));
    // int i = 2;

    // while (i < argc)
	// {
	// 	n = ft_atoi(argv[i]);
	// 	if (argv[i] == NULL)
	// 		break ;
	// 	fill_list(&stack->a, n);
	// 	i++;
	// }
	// p_all(stack, B);
	// print_stack(stack->a);
	// print_stack(stack->b);
	// s_all(stack, A);
	// print_stack(stack->a);
	// r_all(stack, A);
	// print_stack(stack->a);
    t_stack *stack = malloc(sizeof(t_stack));
	t_list *a;
	t_list *b;
	a = malloc(sizeof(*a));
	b = NULL;
	stack->a = a;
	stack->b = b;	
	
	char **test = valid_args(argv, argc);
	fill_stack(stack, test, argc);
	print_stack(stack->a);
    return 0;
}