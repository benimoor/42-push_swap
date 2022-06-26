#include "push_swap.h"

void reset () {
  printf("\033[0m");
}

void print_stack(t_stack *stack) {
    t_list *start_a = stack->a;
    t_list *start_b = stack->b;

    printf("\033[0;36m\n--------------START---------------\n");
    while (stack->a || stack->b) {
        if (stack->a && stack->b) {
            printf("\033[1;33mStack A[%d]\t\033[0;36m|\t\033[1;31mStack B[%d]\n", stack->a->n, stack->b->n);
            stack->b = stack->b->next;
            stack->a = stack->a->next;
        }
        else if (stack->a) {
            printf("\033[1;33mStack A[%d]\t\033[0;36m|\t\n", stack->a->n);
            stack->a = stack->a->next;
        }
        else if (stack->b) {
            printf("          \t\033[0;36m|\t\033[1;31mStack B[%d]\n", stack->b->n);
            stack->b = stack->b->next;
        }
    }
    printf("\033[0;36m---------------END----------------\n");
    reset();
    stack->a = start_a;
    stack->b = start_b;
}

int main(int argc, char **argv)
{
    t_stack *stack = malloc(sizeof(t_stack));

    t_list *a = malloc(sizeof(t_list));
    t_list *b = malloc(sizeof(t_list));

    stack->a = a;
    stack->b = b;

    int i = 1;
    while (i < argc) {
        if (argv[i] == NULL)
            break;
        fill_list(stack->a, ft_atoi(argv[i]));
        i++;
    }

    print_stack(stack);

    p_all(stack, B);

    print_stack(stack);

    s_all(stack, B);

    print_stack(stack);

    return 0;
}