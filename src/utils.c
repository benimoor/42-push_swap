/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:13 by ergrigor          #+#    #+#             */
/*   Updated: 2022/06/26 02:21:53 by ergrigor         ###   ########.fr       */
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

void	put_msg(char *str, int fd)
{
	write(fd, str, (int)(ft_strlen(str)));
}

int	fill_list(t_list *list, int content) {
	t_list *new;
	
	new = ft_lstnew(content);

	if (new == NULL)
		return (-1);

	ft_lstadd_back(&list, new);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	is_negative;
	int	res;

	res = 0;
	is_negative = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		is_negative *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * is_negative);
}

int	swap(t_list *lst)
{
	int	tmp;

	if (!lst->next)
		return (-1);
	tmp = lst->n;
	lst->n = lst->next->n;
	lst->next->n = tmp;
	return (0);
}

int push(t_list *dst, t_list *src) {

	t_list *iter;

	iter = src;
	while (iter->next->next != NULL) {
		iter = iter->next;
	}
	ft_lstadd_back(&dst, iter->next);
	iter->next = NULL;

	return 0;
}

int	p_all(t_stack *stack, t_mode mod) {
	if (mod != A && mod != B)
		return -1;

	if (stack->b != NULL && mod == A) {
		if (push(stack->a, stack->b) < 0) {
			return (-1);
		}
	}
	else if (stack->a != NULL && mod == B) {
		if (push(stack->b, stack->a) < 0)
			return (-1);
	}
	else {
		printf("inside else\n");
		return -1;
	}

	return 0;
}

int	s_all(t_stack *stack, t_mode mod)
{
	if (mod == A)
	{
		if (swap(stack->a) < 0)
			return (-1);
	}
	else if (mod == B)
	{
		if (swap(stack->b) < 0)
			return (-1);
	}
	else if (mod == BOTH)
	{
		if (swap(stack->a) < 0 && swap(stack->b) < 0)
			return (-1);
	}
	else
		return (-1);
	return (0);
}
