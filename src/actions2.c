/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:02:58 by ergrigor          #+#    #+#             */
/*   Updated: 2022/07/07 22:04:00 by ergrigor         ###   ########.fr       */
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

int	r_all(t_stack *stack, t_mode mod)
{
	if (mod == A)
	{
		put_msg("ra\n", 1);
		shift(&stack->a);
	}
	else if (mod == B)
	{
		shift(&stack->b);
		put_msg("rb\n", 1);
	}
	else if (mod == BOTH)
	{
		shift(&stack->a);
		shift(&stack->b);
		put_msg("rr\n", 1);
	}
	else
	{
		put_msg("Error in sort (ra or rb or rr)\n", 2);
		return (-1);
	}
	return (0);
}

int	rr_all(t_stack *stack, t_mode mod)
{
	if (mod == A)
	{
		put_msg("rra\n", 1);
		shift_rr(&stack->a);
	}
	else if (mod == B)
	{
		shift_rr(&stack->b);
		put_msg("rrb\n", 1);
	}
	else if (mod == BOTH)
	{
		shift_rr(&stack->a);
		shift_rr(&stack->b);
		put_msg("rrr\n", 1);
	}
	else
	{
		put_msg("Error in sort (ra or rb or rr)\n", 2);
		return (-1);
	}
	return (0);
}
