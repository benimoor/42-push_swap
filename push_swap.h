/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:51:55 by ergrigor          #+#    #+#             */
/*   Updated: 2022/06/24 20:28:16 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_lst
{
	int				n;
	struct s_lst	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	int		len;
}	t_stack;

size_t	ft_strlen(const char *str);
int		s_all(t_lst	*a, t_lst *b, int mode);
int		pa(t_lst *a, t_lst *b);
int		pb(t_lst *a, t_lst *b);
int		ra(t_lst *a);

#endif
