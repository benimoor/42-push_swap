/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:28:13 by ergrigor          #+#    #+#             */
/*   Updated: 2022/07/17 20:04:43 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_list *a)
{
	while (a->next)
	{
		if(a->n < a->next->n)
			a = a->next;
		else
			return (-1);
	}
	return (0);
		
}

void	sort_3(t_stack *stack)
{
	if ((stack->a->n < stack->a->next->n) && (stack->a->next->n >
	 stack->a->next->next->n))
	{
		rr_all(stack, A);
		if(sorted(stack->a) < 0)
			s_all(stack, A);
	}
	else if (stack->a->n > stack->a->next->n && stack->a->next->n <
	stack->a->next->next->n)
	{
		rr_all(stack, A);
		if (sorted(stack->a) < 0)
			sort_3(stack);
	}
	else if (stack->a->n > stack->a->next->n &&
	stack->a->next->n > stack->a->next->next->n)
	{
		r_all(stack, A);
		s_all(stack, A);
	}
} 

int couynt_shift(t_list *b,int num, int min)
{
	int count;
	
	count = 0;
	while (b->next != NULL && b->n < num && b->n != min)
	{
		b = b->next;
		count++;
	}
	printf("%d", count);
	return (count);
}

void shift_with_count(t_stack *stack, int count)
{
	while (count) 
	{
		r_all(stack, B);
		count--;
	}
	p_all(stack, B);
}

void sort_push(t_stack *stack, int num, int *min, int *max)
{
	int tmp;
	int changed;
	
	tmp = 0;
	changed = 0;
	while (stack->b->next != NULL)
	{
		if (num < *min)
		{
			rr_all(stack, B);
			p_all(stack, B);
			r_all(stack, B);
			r_all(stack, B);
			changed = 1;
			break;
		}
		else if (num < stack->b->n)
		{
			r_all(stack, B);
			tmp++;
		} 
		else
			break;
	}
	if (!changed)
		p_all(stack, B);
	while (tmp != 0)
	{
		rr_all(stack, B);
		tmp--;
	}
	if (num < *min)
		*min = num;
	else if (num > *max)
	{
		rr_all(stack, B);
		s_all(stack, B);
		r_all(stack,B);
		*max = num;
	}
}

void	get_a_stack(t_stack *stack, int *a, int *b, int *c)
{
	t_list	*cursor;
	int	n;
	
	cursor = stack->a;
	while(!cursor->next)
	{
		
	}
}

void merge_ab(t_stack *stack, int *min, int *max)
{

}

void	push_swap(t_stack *stack)
{
	int max;
	int min;
	int a;
	int b;
	int c;
	
	p_all(stack, B);
	p_all(stack, B);
	if (stack->b->n > stack->b->next->n)
		s_all(stack, B);
	min = stack->b->n;
	max = stack->b->next->n;
	get_a_stack(stack, &a, &b, &c);
	while(stack->a->next->next->next != NULL)
		sort_push(stack, stack->a->n, &min, &max);		
	rr_all(stack, B);
	sort_3(stack);

//***************************************************

	merge_ab(stack, &min, &max);

	print_stack(stack->a);
	print_stack(stack->b);

	return ;	
}
