/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:28:13 by ergrigor          #+#    #+#             */
/*   Updated: 2022/07/20 21:32:26 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int length(t_list *st)
{
	int length;

	length = 0;
	while(st)
	{
		length++; 
		st = st->next;
	}
	return (length);
}

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

int mid_elemet_of_stack(t_list *st)
{
	int *alt_arr;
	int mid;

	alt_arr = malloc(length(st) * sizeof(int));
	fil_arr(st, alt_arr);
 	selectionSort(length(st), alt_arr);
	mid = alt_arr[length(st) / 2];
	free(alt_arr);
	return (mid);
}

int chunk_arr_length(t_list *st, int mid)
{
	int length;

	length = 0;
	while(st)
	{
		if (st->n < mid)
			length++; 
		st = st->next;
	}
	return (length);
}

int *chunk(t_stack *stack)
{
	int mid;
	int prev_length;
	int i;
	int *chunk_arr;
	
	mid = mid_elemet_of_stack(stack->a);
	chunk_arr = malloc(chunk_arr_length(stack->a, mid) * sizeof(int));
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
	return (chunk_arr);
}
 
void print_chunk(int *chunk) // will be deleted
{
	int i = 0;

	printf("chunk=========\n");
	while (chunk[i])
	{
		printf("%d   ",chunk[i]);
		i++;
	}
	printf("\n");
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

void sorting_first_3(t_stack *stack)
{
	if (stack->a->n > stack->a->next->n)
		s_all(stack, A);
	p_all(stack, A);
}

int count_length_arr(int *arr)
{
	int length;

	length = (int)sizeof(arr) / (int)sizeof(arr[0]);
	return (length);
}

void sort_swap(t_stack *stack)
{
	if (stack->a->n < stack->a->next->n)
		s_all(stack, B);
	p_all(stack, A);
	p_all(stack, A);
}

void analis_sort(t_stack *stack, int last_chunk_index, int **chunks_arr)
{
	(void)stack;
	// int mid;
	// last_chunk_index--;
	while (last_chunk_index)
	{
		print_chunk(chunks_arr[last_chunk_index - 1]);
	// 	mid = count_length_arr(chunks_arr[last_chunk_index]) / 2;
	// 	// mid = chunks_arr[last_chunk_index][mid];
	// 	printf("%d \n", mid);
	// 	/// petqa array chanker anel u sortavorel 
		last_chunk_index--;
	}
	// printf("%d \n", mid);
}

void sorting_rest(t_stack *stack, int last_chunk_index, int **chunks_arr)
{
	if (count_length_arr(chunks_arr[last_chunk_index - 1]) == 2)
	{
		sort_swap(stack);
		last_chunk_index--;
	}
	// while (length(stack->b) > 1)
	// {
		analis_sort(stack, last_chunk_index, chunks_arr);
	// }
}

void sorting(t_stack *stack)
{
	int **chunks_arr;
	int last_chunk_index;

	chunks_arr = malloc(sizeof(int *) * length(stack->a));
	last_chunk_index = chunks(stack, chunks_arr);
	sorting_first_3(stack);
	sorting_rest(stack, last_chunk_index, chunks_arr);
}

void	push_swap(t_stack *stack)
{
	// coment for testings
	print_stack(stack->a);
	print_stack(stack->b);
	// sorting(stack); // +
	p_all(stack, B);
	print_stack(stack->a);
	print_stack(stack->b);

	return ;	
}
