/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:07:33 by ergrigor          #+#    #+#             */
/*   Updated: 2022/08/06 15:24:48 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_list	*a;
	t_list	*b;
	char	**test;
	int		i;

	i = 0;
	if (argc == 1)
		return (0);
	stack = malloc(sizeof(t_stack));
	a = malloc(sizeof(*a));
	b = NULL;
	stack->a = a;
	stack->b = b;
	valid_check(argv);
	test = valid_args(argv, argc);
	fill_stack(stack, test);
	push_swap(stack);
	while (test[i])
		free(test[i++]);
	free(test);
	free(stack->a);
	free(stack);
	free(a);
	return (0);
}
