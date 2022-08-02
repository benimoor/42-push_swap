/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:28:13 by ergrigor          #+#    #+#             */
/*   Updated: 2022/08/02 20:59:32 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void indexing(t_list *a, int *arr, int size)
{
	int i;
	int j;
	t_list *cursor;
	
	i = 0;
	cursor = a;
	while (i < size)
	{
		j = 0;

		while (cursor->n != arr[j])
		{
			j++;
		}
		cursor->index = j;
		cursor = cursor->next;
		i++;
	}
}

void swap_arr_sorting(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int *arr, t_list *a)
{
    int i;
	int j;
	int min_idx;
	int n;

	n = ft_lstsize(a);
    i = 0;
	while (i < n - 1)
	{
        min_idx = i;
		j = i + 1;
		while (j < n)
		{
            if (arr[j] < arr[min_idx])
                min_idx = j;
			j++;
		}
        swap_arr_sorting(&arr[min_idx], &arr[i]);
		i++;
	}
	indexing(a, arr, n);
}

int matematikakan_hashvarkner(int sz)
{
	if(sz <= 100)
		return ((15 * sz) / 100);
	else
		return((30 * sz) / 500);
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
				r_all(stack, B);
		else if (place > sz / 2)
			while (stack->b->index != sz - 1)
				rr_all(stack, B);
		p_all(stack, A);
		place = 0;
		sz--;
	}
}

void push_to_b(t_stack *stack)
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
			print_stack(stack->a);
			p_all(stack, B);
			print_stack(stack->b);
			r_all(stack, B);
			print_stack(stack->a);

			count++;
		}
		else if (stack->a->index <= count + range)
		{
			p_all(stack, B);
			count++;
		}
		else
			r_all(stack, A);
	}
	print_stack(stack->a);
	print_stack(stack->b);
	push_to_a(stack);
}


void get_indexs(t_list *cursor)
{
	int i;
	int lst_size;
	int *arr;
	t_list *a;

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
	selectionSort(arr, cursor);
	free(arr);
}


void	push_swap(t_stack *stack)
{
	// print_stack(stack->a);
	// print_stack(stack->b);
	// printf("=========[Start]=========");
	int	size;
	
	get_indexs(stack->a);
	size = ft_lstsize(stack->a);
	if (size > 5)
	{
		push_to_b(stack);
	}
	return ;	
}
