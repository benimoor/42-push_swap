/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:13 by ergrigor          #+#    #+#             */
/*   Updated: 2022/06/24 20:21:25 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	put_mssg(char *str, int fd)
{
	write(fd, str, (int)(ft_strlen(str)));
}

void	swap(t_lst *a, t_lst *b)
{
	int	tmp;

	tmp = a->n;
	a->n = b->n;
	b->n = tmp;
}
/* 
	1 -> sa
	2-> sb
	3-> ss
  */

int	s_all(t_lst	*a, t_lst *b, int mode)
{
	if (mode == 1)
	{
		swap(a, a->next);
		put_mssg("sa\n", 1);
	}
	else if (mode == 2)
	{
		swap(b, b->next);
		put_mssg("sb\n", 1);
	}
	else if (mode == 3)
	{
		swap(a, a->next);
		swap(b, b->next);
		put_mssg("ss\n", 1);
	}
	else
		return (-1);
	return (0);
}

int	pa(t_lst *a, t_lst *b)
{
	t_lst	cur;

	if (!b)
		return (1);
	cur = *b;
	if (b->next)
	{
		b->prev = 0;
		b = b->next;
	}
	cur.prev = 0;
	cur.next = a;
	a->prev = &cur;
	a = a->prev;
	put_mssg("pa\n", 1);
	return (0);
}

int	pb(t_lst *a, t_lst *b)
{
	t_lst	cur;

	if (!a)
		return (1);
	cur = *a;
	if (a->next)
	{
		a->prev = 0;
		a = a->next;
	}
	cur.prev = 0;
	cur.next = b;
	b->prev = &cur;
	b = b->prev;
	put_mssg("pb\n", 1);
	return (0);
}

int	ra(t_lst *a)
{
	t_lst	cur;
	t_lst	first;
	
	cur = *a;
	if (a->next == 0)
		return (1);
	*a = *a->next;
	*a->prev = NULL;
	first = a;
	while (*a->next != 0)
		*a = a->next;
	*a->next = &cur;
	cur.prev = *a;
	cur.next = 0;
	*a = &first;
	return (0);
}