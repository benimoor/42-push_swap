/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_src1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:48:17 by smikayel          #+#    #+#             */
/*   Updated: 2022/07/24 17:50:18 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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