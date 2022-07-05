/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:13 by ergrigor          #+#    #+#             */
/*   Updated: 2022/07/05 14:52:21 by ergrigor         ###   ########.fr       */
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

int	fill_list(t_list **lst, int content)
{
	t_list *new;

	new = ft_lstnew(content);
	if(new == NULL)
		return (-1);
	ft_lstadd_back(lst, new);	
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

int	push(t_list **dst, t_list **src)
{
	t_list	*tmp;

	tmp = *src;
	if ((*src)->next)
		*src = (*src)->next;
	tmp->next = NULL;
	ft_lstadd_front(dst, tmp);
	return (0);
}

int	p_all(t_stack *stack, t_mode mod)
{
	if (mod != A && mod != B)
		return (-1);
	if (stack->b != NULL && mod == A)
	{
		if (push(&stack->a, &stack->b) < 0)
			return (-1);
		put_msg("pa\n", 1);
	}
	else if (stack->a != NULL && mod == B)
	{
		if (push(&stack->b, &stack->a) < 0)
			return (-1);
		put_msg("pb\n", 1);
	}
	else
	{
		put_msg("Error in sort (pa or pb)\n", 2);
		return (-1);
	}
	return (0);
}

int	s_all(t_stack *stack, t_mode mod)
{
	if (mod == A)
	{
		if (swap(stack->a) < 0)
			return (-1);
		put_msg("sa\n", 1);
	}
	else if (mod == B)
	{
		if (swap(stack->b) < 0)
			return (-1);
		put_msg("sb\n", 1);
	}
	else if (mod == BOTH)
	{
		if (swap(stack->a) < 0 && swap(stack->b) < 0)
			return (-1);
		put_msg("ss\n", 1);
	}
	else
	{
		put_msg("Error in sort (sa or sb or ss)\n", 2);
		return (-1);
	}
	return (0);
}

int	shift(t_list **lst)
{
	t_list	*iter;
	t_list	*start;
	t_list	*cur;

	start = (*lst)->next;
	cur = *lst;
	iter = ft_lstlast(*lst);
	iter->next = cur;
	cur->next = NULL;
	*lst = start;
	return (0);
}

int		r_all(t_stack *stack, t_mode mod)
{
	if (mod == A)
	{
		put_msg("ra\n", 1);
		shift(&stack->a);
	}
	else if (mod == B)
	{
		shift(&stack->b);
		put_msg("rb\n", 1);
	}
	else if (mod == BOTH)
	{
		shift(&stack->a);
		shift(&stack->b);
		put_msg("rr\n", 1);
	}
	else
	{
		put_msg("Error in sort (ra or rb or rr)\n", 2);
		return (-1);
	}
	return (0);
}
