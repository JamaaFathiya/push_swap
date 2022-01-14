/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:20:55 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/14 13:10:20 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_stack *a, int flag)
{
    if (is_empty(a))
        return;
    inhale(a->top->data, a);
    pop(a);
    if (flag == 1)
        write (1, "ra\n", 3);
}

void    rb(t_stack *b, int flag)
{
    if (is_empty(b))
        return;
    inhale(b->top->data, b);
    pop(b);
    if (flag == 1)
        write (1, "rb\n", 3);
}

void    rr(t_stack *a, t_stack *b)
{
    
    ra(a, 0);
    rb(b, 0);
    write (1, "rr\n", 3);
}