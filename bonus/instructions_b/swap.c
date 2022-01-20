/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:36:52 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/20 03:08:14 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack *a, int flag)
{
	int	tmp;

	if (is_empty(a) || a->size == 1)
		return ;
	tmp = a->top->data;
	a->top->data = a->top->next->data;
	a->top->next->data = tmp;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int flag)
{
	int	tmp;

	if (is_empty(b) || b->size == 1)
		return ;
	tmp = b->top->data;
	b->top->data = b->top->next->data;
	b->top->next->data = tmp;
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	if (is_empty(a) || is_empty(b))
		return ;
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}
