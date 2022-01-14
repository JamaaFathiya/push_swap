/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:38:09 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/14 13:08:53 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa(t_stack *a, t_stack *b)
{
    if (is_empty(b))
        return;
    push(b->top->data, a);
    pop(b);
    write(1, "pa\n", 3);
}

void    pb(t_stack *b, t_stack *a)
{
    if (is_empty(a))
        return;
    push(a->top->data, b);
    pop(a);
    write(1, "pb\n", 3);
}