/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:07:33 by ergrigor          #+#    #+#             */
/*   Updated: 2022/11/20 00:59:18 by ergrigor         ###   ########.fr       */
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
		if (arg_check(test) != 0 || *test == NULL)
		{
			free_dp(&test);
			write(2, "error\n", ft_strlen("error\n"));
			exit(1);
		}
		stack = make_stack(&test);
		checker(stack);
		free_stack(stack);
	}
	return (0);
}
