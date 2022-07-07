/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:01:56 by ergrigor          #+#    #+#             */
/*   Updated: 2022/07/07 22:02:43 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list *lst)
{
	int	tmp;

	if (!lst->next)
		return (-1);
	tmp = lst->n;
	lst->n = lst->next->n;
	lst->next->n = tmp;
	return (0);
}

int	push(t_list **dst, t_list **src)
{
	t_list	*tmp;

	tmp = *src;
	if ((*src)->next)
		*src = (*src)->next;
	tmp->next = NULL;
	ft_lstadd_front(dst, tmp);
	return (0);
}

int	p_all(t_stack *stack, t_mode mod)
{
	if (mod != A && mod != B)
		return (-1);
	if (stack->b != NULL && mod == A)
	{
		if (push(&stack->a, &stack->b) < 0)
			return (-1);
		put_msg("pa\n", 1);
	}
	else if (stack->a != NULL && mod == B)
	{
		if (push(&stack->b, &stack->a) < 0)
			return (-1);
		put_msg("pb\n", 1);
	}
	else
	{
		put_msg("Error in sort (pa or pb)\n", 2);
		return (-1);
	}
	return (0);
}

int	s_all(t_stack *stack, t_mode mod)
{
	if (mod == A)
	{
		if (swap(stack->a) < 0)
			return (-1);
		put_msg("sa\n", 1);
	}
	else if (mod == B)
	{
		if (swap(stack->b) < 0)
			return (-1);
		put_msg("sb\n", 1);
	}
	else if (mod == BOTH)
	{
		if (swap(stack->a) < 0 && swap(stack->b) < 0)
			return (-1);
		put_msg("ss\n", 1);
	}
	else
	{
		put_msg("Error in sort (sa or sb or ss)\n", 2);
		return (-1);
	}
	return (0);
}

int	shift(t_list **lst)
{
	t_list	*iter;
	t_list	*start;
	t_list	*cur;

	start = (*lst)->next;
	cur = *lst;
	iter = ft_lstlast(*lst);
	iter->next = cur;
	cur->next = NULL;
	*lst = start;
	return (0);
}
