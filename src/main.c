#include "push_swap.h"

void print_stack(t_stack *stack) {
    t_list *start_a = stack->a;
    t_list *start_b = stack->b;

    printf("\n--------------START---------------\n");
    while (stack->a || stack->b) {
        if (stack->a && stack->b) {
            printf("Stack A[%d]\t|\tStack B[%d]\n", stack->a->n, stack->b->n);
            stack->b = stack->b->next;
            stack->a = stack->a->next;
        }
        else if (stack->a) {
            printf("Stack A[%d]\t|\t\n", stack->a->n);
            stack->a = stack->a->next;
        }
        else if (stack->b) {
            printf("          \t|\tStack B[%d]\n", stack->b->n);
            stack->b = stack->b->next;
        }
    }
    printf("---------------END----------------\n");

    stack->a = start_a;
    stack->b = start_b;
}

int main()
{
    t_stack *stack = malloc(sizeof(t_stack));

    t_list *a = malloc(sizeof(t_list));
    t_list *b = malloc(sizeof(t_list));

    stack->a = a;
    stack->b = b;

    stack->a->n = 17;
    stack->a->next = ft_lstnew(2);

    stack->b->n = 25;
    stack->b->next = ft_lstnew(4);

    print_stack(stack);

    p_all(stack, B);

    print_stack(stack);

    s_all(stack, B);

    print_stack(stack);

    return 0;
}