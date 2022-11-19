/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:28:13 by ergrigor          #+#    #+#             */
/*   Updated: 2022/08/05 17:14:27 by ergrigor         ###   ########.fr       */
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

void	indexing(t_list *a, int *arr, int size)
{
	int		i;
	int		j;
	t_list	*cursor;

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

void	swap_arr_sorting(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	selection_sort(int *arr, t_list *a)
{
	int	i;
	int	j;
	int	min_idx;
	int	n;

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
		swap_arr_sorting (&arr[min_idx], &arr[i]);
		i++;
	}
	indexing(a, arr, n);
}

int	matematikakan_hashvarkner(int sz)
{
	if (sz <= 100)
		return ((15 * sz) / 100);
	else
		return ((30 * sz) / 500);
}
