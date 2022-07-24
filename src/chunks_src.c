/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_src.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:40:41 by smikayel          #+#    #+#             */
/*   Updated: 2022/07/24 17:42:55 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_arr_sorting(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int n, int *arr)
{
    int i;
	int j;
	int min_idx;
    i = 0;
	while (i < n- 1)
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
}

void fil_arr(t_list *st, int *arr)
{
	int i;

	i = 0;
	while (st)
	{
		arr[i] = st->n;
		st = st->next;
		i++;
	}
}

int *chunk(t_stack *stack)
{
	int mid;
	int prev_length;
	int i;
	int *chunk_arr;
	
	mid = mid_elemet_of_stack(stack->a);
	chunk_arr = malloc(chunk_arr_length(stack->a, mid) * sizeof(int) + 4);
	i = 0;
	prev_length = length(stack->a) / 2 + (length(stack->a) % 2);
	while (length(stack->a) > prev_length)
	{
		if (stack->a->n < mid)
		{
			chunk_arr[i] = stack->a->n;
			p_all(stack, B);
			i++;
		}
		else 
			r_all(stack, A);
	}
	chunk_arr[i] = (int)NULL;
	return (chunk_arr);
}

int chunks(t_stack *stack, int **chunks_arr)
{
	int i;

	i = 0;
	while (length(stack->a) > 2)
	{
		chunks_arr[i] = chunk(stack);	
		i++;
	}
	return (i - 1);
}