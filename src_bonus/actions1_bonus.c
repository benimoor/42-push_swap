/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:01:56 by ergrigor          #+#    #+#             */
/*   Updated: 2022/11/19 23:55:36 by ergrigor         ###   ########.fr       */
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
	ft_lstadd_front(dst, tmp);
	if ((*src)->next == NULL)
		*src = 0x0;
	return (0);
}

int	ft_pb(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->a;
	stack->a = stack->a->next;
	tmp->next = NULL;
	if (!stack->b)
		stack->b = tmp;
	else
		ft_lstadd_front(&stack->b, tmp);
	return (0);
}

int	ft_pa(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->b;
	stack->b = stack->b->next;
	tmp->next = NULL;
	if (!stack->a)
		stack->a = tmp;
	else
		ft_lstadd_front(&stack->a, tmp);
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
