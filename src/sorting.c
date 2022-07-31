/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 11:09:53 by ergrigor          #+#    #+#             */
/*   Updated: 2022/07/31 14:44:06 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_list *a)
{
	while (a->next)
	{
		if (a->n < a->next->n)
			a = a->next;
		else
			return (-1);
	}
	return (0);
}

void	sort_3(t_stack *stack)
{
	if ((stack->a->n < stack->a->next->n)
		&& (stack->a->next->n > stack->a->next->next->n))
	{
		rr_all(stack, A);
		if (sorted(stack->a) < 0)
			s_all(stack, A);
	}
	else if (stack->a->n > stack->a->next->n
		&& stack->a->next->n < stack->a->next->next->n)
	{
		rr_all(stack, A);
		if (sorted(stack->a) < 0)
			sort_3(stack);
	}
	else if (stack->a->n > stack->a->next->n
		&& stack->a->next->n > stack->a->next->next->n)
	{
		r_all(stack, A);
		s_all(stack, A);
	}
}

int	get_min(t_list *a)
{
	int		n;
	t_list	*cursor;

	cursor = a;
	n = cursor->n;
	while (cursor->next)
	{
		if (n > cursor->next->n)
			n = cursor->next->n;
		cursor = cursor->next;
	}
	return (n);
}

int	get_max(t_list *a)
{
	int		n;
	t_list	*cursor;

	cursor = a;
	n = cursor->n;
	while (cursor->next)
	{
		if (n < cursor->next->n)
			n = cursor->next->n;
		cursor = cursor->next;
	}
	return (n);
}

int	sort_get_med(int *arr, int size)
{
	int	x;
	int	y;
	int	temp;

	x = 0;
	while (x < size - 1)
	{
		y = x;
		while (y < size - 1)
		{
			if (arr[y] > arr[y + 1])
			{
				temp = arr[y];
				arr[y] = arr[y + 1];
				arr[y + 1] = temp;
			}
			y++;
		}
		x++;
	}
	return (arr[size / 2]);
}

int	get_med(t_list *a)
{
	int	size;
	int	i;
	int	*arr;
	int	res;

	size = ft_lstsize(a);
	arr = malloc(size);
	i = 0;
	if (!arr)
	{
		put_msg("Error to get median", 2);
		exit (-1);
	}
	while (i < size && a)
	{
		arr[i] = a->n;
		i++;
		a = a->next;
	}
	res = sort_get_med(arr, size);
	free(arr);
	return (res);
}

int	get_pos(t_stack *stack, int num)
{
	t_list	*cursor;
	
	cursor = stack->a;
	while(cursor)
	{
		if (cursor->n)
	}
}
t_qyal	get_min_qyal(t_stack *stack)
{
	t_qyal	*min_qyal;
	t_list	*cursor;
	int		pos;

	cursor = stack->b;
	min_qyal = malloc(sizeof(t_qyal));
	while (cursor)
	{
		min_qyal->num = cursor->n;
		pos = get_pos(stack, min_qyal->num);
		
	}
	return (min_qyal);
}

void	push_to_a(t_stack *stack)
{
	t_qyal	min_qyal;

	min_qyal = get_min_qyal(stack);
}

void	push_to_b(t_stack *stack)
{
	int		lst_size;
	int		min;
	int		max;
	int		med;
	t_list	*cursor;

	min = get_min(stack->a);
	med = get_med(stack->a);
	max = get_max(stack->a);
	lst_size = ft_lstsize(stack->a);
	while (lst_size != 4)
	{
		cursor = stack->a;
		lst_size = ft_lstsize(cursor);
		if (cursor->n == min || cursor->n == med || cursor->n == max)
			r_all(stack, A);
		p_all(stack, B);
		cursor = cursor->next;
	}
}

void	get_presorted_a(t_stack *stack)
{
	if ((stack->a->n < stack->a->next->n
			&& stack->a->n > stack->a->next->next->n)
		|| (stack->a->n > stack->a->next->n
			&& stack->a->next->n < stack->a->next->next->n))
		return ;
	else
	{
		if (stack->a->n < stack->a->next->n
			&& stack->a->next->n < stack->a->next->next->n)
			r_all(stack, A);
		else
		{
			s_all(stack, A);
			get_presorted_a(stack);
		}
	}
}

void	push_swap(t_stack *stack)
{
	if (sorted(stack->a) == 0)
		return ;
	push_to_b(stack);
	get_presorted_a(stack);
	push_to_a(stack);
}

void	sorting(t_stack *stack)
{
	int	size;

	size = ft_lstsize(stack->a);
	if (size == 1)
	{
		return ;
	}
	else if (size == 2)
	{
		if (stack->a->n < stack->b->next->n)
			s_all(stack, A);
	}
	else if (size == 3)
	{
		sort_3(stack);
	}
	else
	{
		push_swap(stack);
	}
}
