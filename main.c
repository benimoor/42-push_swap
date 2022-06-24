/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:34:19 by ergrigor          #+#    #+#             */
/*   Updated: 2022/06/24 20:26:25 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main()
{
    t_lst *a = malloc(sizeof(t_lst)); 
    t_lst *b = malloc(sizeof(t_lst));
    t_lst *c = malloc(sizeof(t_lst));
    
    a->n = 1;
    a->next = b;
    b->n = 2;
    b->next = c;
    c->n = 3;
    c->next = 0;
    ra(a);
    while(a)
    {
        printf("%d\n", a->n);
        a = a->next;
    }
    return 0;
}