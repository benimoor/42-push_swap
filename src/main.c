#include "../includes/push_swap.h"
#include <stdio.h>

int main()
{
    t_stack *stack = malloc(sizeof(t_stack));

    t_list *a = malloc(sizeof(t_list));
    t_list *b = malloc(sizeof(t_list));

    stack->a = a;
    stack->b = b;

    stack->a->n = 5;
    stack->a->next = ft_lstnew(2);

    printf("a->n = %d\n", stack->a->n);
    printf("a->next->n = %d\n", stack->a->next->n);

    s_all(stack, B);

    printf("a->n = %d\n", stack->a->n);
    printf("a->next->n = %d\n", stack->a->next->n);

    return 0;
}