/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:20:29 by ergrigor          #+#    #+#             */
/*   Updated: 2022/11/19 18:21:23 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

char	*join_str(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	if (s1)
		free(s1);
	return (str);
}

void	free_dp(char ***group)
{
	int	i;

	i = -1;
	if (group || *group)
	{
		while ((*group)[++i] != NULL)
			free((*group)[i]);
		free(*group);
		*group = 0x0;
	}
}

t_stack	*make_stack(char ***group)
{
	t_stack	*stack;
	char	**tp;
	t_list	*tmp;
	int		i;

	stack = malloc(sizeof(t_stack));
	stack->b = NULL;
	tp = *group;
	stack->a = ft_lstnew(ft_atoi(tp[0]));
	i = 1;
	while (tp[i])
	{
		tmp = ft_lstnew(ft_atoi(tp[i]));
		ft_lstadd_back(&stack->a, tmp);
		i++;
	}
	ft_lstlast(stack->a)->next = NULL;
	free_dp(group);
	return (stack);
}
