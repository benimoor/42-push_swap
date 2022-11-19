/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:10:41 by ergrigor          #+#    #+#             */
/*   Updated: 2022/11/19 23:53:36 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_stack *stack)
{
	if (stack->a->n > stack->a->next->n)
		s_all_ch(stack, A);
}

void	sort3(t_stack *stack)
{
	if ((stack->a->n < stack->a->next->n) && (stack->a->next->n
			> stack->a->next->next->n))
	{
		rr_all_ch(stack, A);
		if (sorted(stack->a) < 0)
			s_all_ch(stack, A);
	}
	else if (stack->a->n > stack->a->next->n && stack->a->next->n
		< stack->a->next->next->n)
	{
		rr_all_ch(stack, A);
		if (sorted(stack->a) < 0)
			sort3(stack);
	}
	else if (stack->a->n > stack->a->next->n
		&& stack->a->next->n > stack->a->next->next->n)
	{
		r_all_ch(stack, A);
		s_all_ch(stack, A);
	}
}

void	push_min(t_stack *stack, int min)
{
	while (stack->a->n != min)
	{
		if (stack->a->n == min || stack->a->next->n == min)
			r_all_ch(stack, A);
		else
			rr_all_ch(stack, A);
	}
	p_all_ch(stack, B);
}

void	sort5(t_stack *stack)
{
	t_list	*cursor;
	int		min;

	while (ft_lstsize(stack->a) != 3)
	{
		cursor = stack->a;
		min = cursor->n;
		while (cursor)
		{
			if (cursor->n < min)
				min = cursor->n;
			cursor = cursor->next;
		}
		cursor = stack->a;
		push_min(stack, min);
	}
	sort3(stack);
	while (stack->b)
		p_all_ch(stack, A);
}

void	push_swap(t_stack *stack)
{
	int	size;

	get_indexs(stack->a);
	size = ft_lstsize(stack->a);
	if (sorted(stack->a) == 0)
		return ;
	if (size == 1)
		return ;
	else if (size == 2)
		sort2(stack);
	else if (size == 3)
		sort3(stack);
	else if (size <= 5)
		sort5(stack);
	else if (size > 5)
		push_to_b(stack);
	return ;
}
