/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:07:33 by ergrigor          #+#    #+#             */
/*   Updated: 2022/11/22 22:54:39 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_list	*start;
	t_list	*next;

	while (stack && stack->a)
	{
		start = stack->a;
		next = stack->a;
		while (next->next)
		{
			start = next;
			next = next->next;
		}
		if (start == next)
		{
			free(stack->a);
			stack->a = NULL;
		}
		else
		{
			start->next = NULL;
			free(next);
		}
	}
	free(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**test;

	if (argc > 1)
	{
		test = join_args(argc, argv);
		if (test == NULL)
			return (write(2, "Error\n", ft_strlen("error\n")), 1);
		if (arg_check(test) != 0)
			free_dp(&test, 1);
		stack = make_stack(&test);
		if (checker(stack) == -1)
			return (free_stack(stack),
				write(2, "Error\n", ft_strlen("error\n")), 1);
		free_stack(stack);
	}
	return (0);
}
