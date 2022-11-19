/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:08:05 by ergrigor          #+#    #+#             */
/*   Updated: 2022/11/19 23:56:33 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	shift(t_list **lst)
{
	t_list	*iter;
	t_list	*start;
	t_list	*cur;

	if (!(*lst)->next)
		return (0);
	start = (*lst)->next;
	cur = *lst;
	iter = ft_lstlast(*lst);
	iter->next = cur;
	cur->next = NULL;
	*lst = start;
	return (0);
}

void	push_to_a(t_stack *stack)
{
	t_list		*first;
	long int	place;
	long int	sz;

	sz = ft_lstsize(stack->b);
	place = 0;
	while (stack->b)
	{
		first = stack->b;
		while (sz - 1 != stack->b->index)
		{
			place++;
			stack->b = stack->b->next;
		}
		stack->b = first;
		if (place <= sz / 2)
			while (stack->b->index != sz - 1)
				r_all_ch(stack, B);
		else if (place > sz / 2)
			while (stack->b->index != sz - 1)
				rr_all_ch(stack, B);
		p_all_ch(stack, A);
		place = 0;
		sz--;
	}
}

void	push_to_b(t_stack *stack)
{
	long int	count;
	long int	range;
	long int	sz;

	count = 0;
	sz = ft_lstsize(stack->a);
	while (stack->a)
	{
		range = matematikakan_hashvarkner(sz);
		if (stack->a->index <= count)
		{
			p_all_ch(stack, B);
			r_all_ch(stack, B);
			count++;
		}
		else if (stack->a->index <= count + range)
		{
			p_all_ch(stack, B);
			count++;
		}
		else
			r_all_ch(stack, A);
	}
	push_to_a(stack);
}

void	get_indexs(t_list *cursor)
{
	int		i;
	int		lst_size;
	int		*arr;
	t_list	*a;

	a = cursor;
	lst_size = ft_lstsize(a);
	arr = malloc(lst_size * sizeof(int));
	i = 0;
	while (i < lst_size)
	{
		arr[i] = a->n;
		a = a->next;
		i++;
	}
	selection_sort(arr, cursor);
	free(arr);
}
