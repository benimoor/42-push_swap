/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:04:21 by ergrigor          #+#    #+#             */
/*   Updated: 2022/08/05 17:17:21 by ergrigor         ###   ########.fr       */
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

char	**valid_args(char **argv, int argc)
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
	res = ft_split(str, ' ');
	free(str);
	if (!res)
		return (NULL);
	i = 0;
	if (validation(res) < 0)
	{
		put_msg("Error", 2);
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

int	fill_stack(t_stack *stack, char **res)
{
	int	i;
	int	n;

	i = 1;
	stack->a = ft_lstnew(ft_atoi(res[0]));
	while (res[i] != NULL)
	{
		n = ft_atoi(res[i]);
		if (res[i] == NULL)
			break ;
		fill_list(&stack->a, n);
		i++;
	}
	return (0);
}

void	valid_check(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!argv[i] || !*argv[i])
		{
			put_msg("Enter valid arguments", 2);
			exit(0);
		}
		i++;
	}
}
