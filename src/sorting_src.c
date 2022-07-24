/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_src.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:46:53 by smikayel          #+#    #+#             */
/*   Updated: 2022/07/24 17:56:56 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sorting_first_2(t_stack *stack)
{
	if (stack->a->n > stack->a->next->n)
		s_all(stack, A);
}

int count_length_arr(int *arr)
{
	int length;
    int i;

    i = 0;
    length = 0;
    while (arr[i])
    {
        length++;
        i++;
    }
	// length = (int)sizeof(arr) / (int)sizeof(arr[0]);
	return (length);
}

void sort_swap(t_stack *stack)
{
	if (stack->b->n < stack->b->next->n)
		s_all(stack, B);
	p_all(stack, A);
	p_all(stack, A);
}