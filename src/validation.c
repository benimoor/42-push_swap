/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:04:21 by ergrigor          #+#    #+#             */
/*   Updated: 2022/07/07 22:35:20 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validation(char **res)
{
	int	n;
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (res[i] != NULL)
	{
		n = ft_atoi(res[i]);
		j = i;
		while (res[++j] != NULL)
		{
			tmp = ft_atoi(res[j]);
			if (n == tmp)
			{
				i = 0;
				while (res[i])
					free(res[i++]);
				return (-1);
			}
		}
		i++;
	}
	return (1);
}

char **valid_args(char **argv, int argc)
{
	int		i;
	char	*str;
	char	*tmp;
	char	**res;

	str = NULL;
	i = 1;
	while (i < argc)
	{
		tmp = ft_strjoin(ft_strdup(argv[i++]), " ");
		str = ft_strjoin(str, tmp);
		free(tmp);
	}
	free(str);
	res = ft_split(str, ' ');
	if (!res)
		return (NULL);
	i = 0;
	while(res[i])
		printf("%s\n", res[i++]);
	if (validation(res) < 0)
	{
		free(res);
		put_msg("Duplicate numbers", 2);
		exit (-1);
	}
	return (res);
}

int	fill_list(t_list **lst, int content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (new == NULL)
		return (-1);
	ft_lstadd_back(lst, new);
	return (0);
}

int	fill_stack(t_stack *stack, char **res, int argc)
{
	int	i;
	int	n;

	i = 1;
	stack->a = ft_lstnew(ft_atoi(res[0]));
	while (i < argc - 1)
	{
		n = ft_atoi(res[i]);
		if (res[i] == NULL)
			break ;
		fill_list(&stack->a, n);
		i++;
	}
	return (0);
}