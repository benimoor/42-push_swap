#include "push_swap.h"

int	s_all_ch(t_stack *stack, t_mode mod)
{
	if (mod == A)
	{
		if (swap(stack->a) < 0)
			return (-1);
	}
	else if (mod == B)
	{
		if (swap(stack->b) < 0)
			return (-1);
	}
	else if (mod == BOTH)
	{
		if (swap(stack->a) < 0 && swap(stack->b) < 0)
			return (-1);
	}
	else
	{
		return (-1);
	}
	return (0);
}


int	r_all_ch(t_stack *stack, t_mode mod)
{
	if (mod == A)
	{
		if (stack->a->next == NULL)
			return (0);
		shift(&stack->a);
	}
	else if (mod == B)
	{
		if (stack->b->next == NULL)
			return (0);
		shift(&stack->b);
	}
	else if (mod == BOTH)
	{
		shift(&stack->a);
		shift(&stack->b);
	}
	return (0);
}

int	rr_all_ch(t_stack *stack, t_mode mod)
{
	if (mod == A)
	{
		if (stack->a->next == NULL)
			return (0);
		shift_rr(&stack->a);
	}
	else if (mod == B)
	{
		if (stack->b->next == NULL)
			return (0);
		shift_rr(&stack->b);
	}
	else if (mod == BOTH)
	{
		shift_rr(&stack->a);
		shift_rr(&stack->b);
	}
	return (0);
}

int	p_all_ch(t_stack *stack, t_mode mod)
{
	if (mod != A && mod != B)
		return (-1);
	if (stack->b != NULL && mod == A)
	{
		if (ft_pa(stack) < 0)
			return (-1);
	}
	else if (stack->a != NULL && mod == B)
	{
		if (ft_pb(stack) < 0)
			return (-1);
	}
	else
	{
		return (-1);
	}
	return (0);
}