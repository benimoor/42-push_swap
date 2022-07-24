/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_src.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:44:48 by smikayel          #+#    #+#             */
/*   Updated: 2022/07/24 17:45:17 by smikayel         ###   ########.fr       */
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