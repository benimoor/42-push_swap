/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:20:54 by ergrigor          #+#    #+#             */
/*   Updated: 2022/11/22 22:06:46 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	const unsigned char	*str1;
// 	const unsigned char	*str2;
// 	size_t				i;

// 	str1 = (const unsigned char *)s1;
// 	str2 = (const unsigned char *)s2;
// 	i = 0;
// 	if (n == 0)
// 		return (0);
// 	while (str1[i] == str2[i] && i < n - 1 && str1[i])
// 		i++;
// 	return (str1[i] - str2[i]);
// }

int		check_action(char *tmp, t_stack *stack)
{
	if (ft_strncmp(tmp, "sa", 2) == 0 && ft_strlen(tmp) == 2)
		{if (ft_lstsize(stack->a) > 1)
			s_all_ch(stack, A);}
	else if (ft_strncmp(tmp, "sb", 2) == 0 && ft_strlen(tmp) == 3)
		{if (ft_lstsize(stack->b) > 1)
			s_all_ch(stack, B);}
	else if (ft_strncmp(tmp, "ss", 2) == 0 && ft_strlen(tmp) == 3)
		{if (ft_lstsize(stack->a) > 1 && ft_lstsize(stack->b) > 1)
			s_all_ch(stack, BOTH);}
	else if (ft_strncmp(tmp, "ra", 2) == 0 && ft_strlen(tmp) == 3)
		{if (ft_lstsize(stack->a) > 1)
			r_all_ch(stack, A);}
	else if (ft_strncmp(tmp, "rb", 2) == 0 && ft_strlen(tmp) == 3)
		{if (stack->b != NULL && ft_lstsize(stack->b) > 1)
			r_all_ch(stack, B);}
	else if (ft_strncmp(tmp, "rr", 2) == 0 && ft_strlen(tmp) == 3)
		{if (ft_lstsize(stack->a) > 1 && ft_lstsize(stack->b) > 1)
			r_all_ch(stack, BOTH);}
	else if (ft_strncmp(tmp, "rra", 3) == 0 && ft_strlen(tmp) == 4)
		{if (ft_lstsize(stack->a) > 1)
			rr_all_ch(stack, A);}
	else if (ft_strncmp(tmp, "rrb", 3) == 0 && ft_strlen(tmp) == 4)
		{if (ft_lstsize(stack->b) > 1)
			rr_all_ch(stack, B);}
	else if (ft_strncmp(tmp, "rrr", 3) == 0 && ft_strlen(tmp) == 4)
		{if (ft_lstsize(stack->a) > 1 && ft_lstsize(stack->b) > 1)
			rr_all_ch(stack, BOTH);}
	else if (ft_strncmp(tmp, "pa", 2) == 0 && ft_strlen(tmp) == 3)
		{if (ft_lstsize(stack->b) > 1)
			p_all_ch(stack, A);}
	else if (ft_strncmp(tmp, "pb", 2) == 0 && ft_strlen(tmp) == 3)
		{if (ft_lstsize(stack->a) > 1)
			p_all_ch(stack, B);}
	else if (!tmp || !*tmp || *tmp == '\n')
		{return (0);}
	else
		{return (-1);}
	return (0);
}

int	checker(t_stack *stack)
{
	char	*tmp;
	int		fd;

	fd = 1;
	while (1)
	{
		if (get_next_line(fd, &tmp))
		{
			if (check_action(tmp, stack) != 0)
			{
				free(tmp);
				return (-1);
			}
			free(tmp);
		}
		else
		{
			if (sorted(stack->a) == 0 && stack->b == NULL)
				write(1, "OK\n", 3);
			else
				write(2, "KO\n", 3);
			return (0);
		}
	}
	if (tmp)
		free(tmp);
	return(0);
}
