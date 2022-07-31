/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:28:13 by ergrigor          #+#    #+#             */
/*   Updated: 2022/07/24 20:35:52 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int get_mid_of_chunk(int *arr)
{
	int mid;
	int length;

	length = count_length_arr(arr);
	selectionSort(length, arr);
	mid = arr[length / 2];
	return (mid);
}

// void mid_big_up(t_stack *stack, int chunk_length, int *arr, int mid)
// {
// 	int i;
	
// 	i = 0;
// 	while (i < (chunk_arr_length - 1))
// 	{
		
// 	}
// }

// void transfer_chunk_sort_back(t_stack *stack, int *arr)
// {
// 	int next;
// 	int mid;
// 	int chunk_length;

// 	next = 1;
// 	chunk_length = count_length_arr(arr);
// 	// while (next)
// 	// {
// 		(void)stack;
// 		mid = get_mid_of_chunk(arr);
// 		printf("%d", mid);
// 		mid_big_up(stack, chunk_length, arr, mid);
// 	// }
// }

void sorting_rest(t_stack *stack, int last_chunk_index, int **chunks_arr)
{
	if (count_length_arr(chunks_arr[last_chunk_index]) == 1)
	{
		p_all(stack, A);
		last_chunk_index--;
	}
	if (count_length_arr(chunks_arr[last_chunk_index]) == 2)
	{
		sort_swap(stack);
		last_chunk_index--;
	}
	print_chunk(chunks_arr[last_chunk_index]);	
	// transfer_chunk_sort_back(stack, chunks_arr[last_chunk_index]);
}

void sorting(t_stack *stack)
{
	int **chunks_arr;
	int last_chunk_index;

	chunks_arr = malloc(sizeof(int *) * length(stack->a));
	last_chunk_index = chunks(stack, chunks_arr);
	sorting_first_2(stack);
	sorting_rest(stack, last_chunk_index, chunks_arr);
	
}

// 4 -5
// 7 8 6
// -5 4 6 7 8
void	push_swap(t_stack *stack)
{
	// coment for testings
	print_stack(stack->a);
	print_stack(stack->b);
	/// 2 u poqr arraynery check anel nor sortel 
	sorting(stack); // +
	// p_all(stack, B);
	print_stack(stack->a);
	print_stack(stack->b);

	return ;	
}
