/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:41:48 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/16 13:19:49 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, int flag)
{
	if (is_empty(a))
		return ;
	push(a->base->data, a);
	exhale(a);
	if (flag == 1)
		write (1, "rra\n", 4);
}

void	rrb(t_stack *b, int flag)
{
	if (is_empty(b))
		return ;
	push(b->base->data, b);
	exhale(b);
	if (flag == 1)
		write (1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 0);
	rrb(b, 0);
	write (1, "rrr\n", 4);
}
