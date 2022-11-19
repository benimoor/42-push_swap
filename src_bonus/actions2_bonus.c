/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:02:58 by ergrigor          #+#    #+#             */
/*   Updated: 2022/11/19 23:56:16 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	shift_rr(t_list **lst)
{
	t_list	*iter;
	t_list	*start;
	t_list	*cur;

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
		shift(&stack->a);
	}
	else if (mod == B)
	{
		shift(&stack->b);
	}
	else if (mod == BOTH)
	{
		shift(&stack->a);
		shift(&stack->b);
	}
	else
	{
		return (-1);
	}
	return (0);
}

int	rr_all_ch(t_stack *stack, t_mode mod)
{
	if (mod == A)
	{
		shift_rr(&stack->a);
	}
	else if (mod == B)
	{
		shift_rr(&stack->b);
	}
	else if (mod == BOTH)
	{
		shift_rr(&stack->a);
		shift_rr(&stack->b);
	}
	else
	{
		return (-1);
	}
	return (0);
}
