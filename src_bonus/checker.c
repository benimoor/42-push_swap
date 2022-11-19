/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:20:54 by ergrigor          #+#    #+#             */
/*   Updated: 2022/11/20 00:15:56 by ergrigor         ###   ########.fr       */
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

void	check_action(char *tmp, t_stack *stack)
{
	if (ft_strncmp(tmp, "sa", 2) == 0)
		s_all_ch(stack, A);
	else if (ft_strncmp(tmp, "sb", 2) == 0)
		s_all_ch(stack, B);
	else if (ft_strncmp(tmp, "ss", 2) == 0)
		s_all_ch(stack, BOTH);
	else if (ft_strncmp(tmp, "ra", 2) == 0)
		r_all_ch(stack, A);
	else if (ft_strncmp(tmp, "rb", 2) == 0)
		r_all_ch(stack, B);
	else if (ft_strncmp(tmp, "rr", 2) == 0)
		r_all_ch(stack, BOTH);
	else if (ft_strncmp(tmp, "rra", 2) == 0)
		rr_all_ch(stack, A);
	else if (ft_strncmp(tmp, "rrb", 2) == 0)
		rr_all_ch(stack, B);
	else if (ft_strncmp(tmp, "rrr", 2) == 0)
		rr_all_ch(stack, BOTH);
	else if (ft_strncmp(tmp, "pa", 2) == 0)
		p_all_ch(stack, A);
	else if (ft_strncmp(tmp, "pb", 2) == 0)
		p_all_ch(stack, B);
}

void	checker(t_stack *stack)
{
	char	*tmp;
	int		fd;

	fd = 1;
	while (get_next_line(fd, &tmp) > 0)
	{
		check_action(tmp, stack);
		free(tmp);
	}
	if (tmp)
		free(tmp);
	close(fd);
}
