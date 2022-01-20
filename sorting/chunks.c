/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:20:14 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/20 14:29:00 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_elem_index(t_stack *a, int elem)
{
	int				index;
	t_stack_node	*tmp;

	index = -1;
	tmp = a->top;
	while (tmp)
	{
		index++;
		if (tmp->data == elem)
			return (index);
		tmp = tmp->next;
	}
	return (index);
}

int	min_elem(t_stack *s)
{
	int				min;
	t_stack_node	*tmp;

	tmp = s->top;
	min = s->top->data;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->data < min)
			min = tmp->data;
	}
	return (min);
}

int	max_elem(t_stack *s)
{
	int				max;
	t_stack_node	*tmp;

	tmp = s->top;
	max = s->top->data;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->data > max)
			max = tmp->data;
	}
	return (max);
}

void	push_to_b(t_stack *b, t_stack *a)
{
	int	i;
	int	index;

	i = 0;
	while (!is_empty(b))
	{
		i = 0;
		index = get_elem_index(b, max_elem(b));
		if (index == -1)
			return ;
		if (index <= b->size / 2)
			while (i++ < index)
				rb(b, 1);
		else
			while (i++ < b->size - index)
				rrb(b, 1);
		pa(a, b);
	}
}

void	sort(t_stack *a,	t_stack *b)
{
	int	min;
	int	max;

	min = min_elem(a);
	max = max_elem(a);
	if (a->size < 100)
		naive_sort(a, b);
	else
		six_twelve_chunks(a, b, min, max);
}
