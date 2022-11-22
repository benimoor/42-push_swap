/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:02:58 by ergrigor          #+#    #+#             */
/*   Updated: 2022/11/22 21:25:00 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	shift_rr(t_list **lst)
{
	t_list	*iter;
	t_list	*start;
	t_list	*cur;

	if (!(*lst) && (*lst)->next == NULL)
		return (0);
	cur = *lst;
	iter = *lst;
	while (iter->next->next)
		iter = iter->next;
	start = iter->next;
	iter->next = NULL;
	start->next = cur;
	*lst = start;
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
