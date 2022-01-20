/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:47:11 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/20 01:04:35 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack	*s)
{
	int	min;

	min = get_elem_index(s, min_elem(s));
	if (min == 1)
	{
		if (s->top->data > s->base->data)
			ra(s, 1);
		else
			sa(s, 1);
	}
	else if (min == 2)
	{
		if (s->top->data > s->top->next->data)
		{
			sa(s, 1);
			rra(s, 1);
		}
		else
			rra(s, 1);
	}
	else
	{
		sa(s, 1);
		ra(s, 1);
	}
}

void	naive_sort(t_stack *a, t_stack *b)
{
	int	index;
	int	i;

	while (!is_sorted(a))
	{
		if (a->size == 3)
			sort_three(a);
		else
		{
			i = 0;
			index = get_elem_index(a, min_elem(a));
			if (index == -1)
				return ;
			if (index <= a->size / 2)
				while (i++ < index)
					ra(a, 1);
			else
				while (i++ < a->size - index)
					rra(a, 1);
			if (!is_sorted(a))
				pb(b, a);
		}
	}
	while (!is_empty(b))
		pa(a, b);
}

int	*one_chunk(t_stack *a, int subdiv)
{
	int				i;
	int				j;
	t_stack_node	*tmp_up;
	t_stack_node	*tmp_down;

	i = 0;
	j = a->size - 1;
	tmp_up = a->top;
	tmp_down = a->base;
	while (i++ <= j--)
	{
		if (tmp_up->data <= subdiv)
			return (&(tmp_up->data));
		else if (tmp_down->data <= subdiv)
			return (&(tmp_down->data));
		tmp_up = tmp_up->next;
		tmp_down = tmp_down->prev;
	}
	return (NULL);
}

void	psh(t_stack *a, t_stack *b, int subdiv)
{
	int	i;
	int	*elem;
	int	index;

	elem = one_chunk(a, subdiv);
	while (elem)
	{
		i = 0;
		index = get_elem_index(a, *elem);
		if (index == -1)
			return ;
		if (index <= a->size / 2)
			while (i++ < index)
				ra(a, 1);
		else
			while (i++ < a->size - index)
				rra(a, 1);
		pb(b, a);
		elem = one_chunk(a, subdiv);
	}
}

void	six_twelve_chunks(t_stack *a, t_stack *b, int min, int max)
{
	int	subdiv;
	int	i;
	int	div;

	i = 1;
	if (a->size >= 100 && a->size < 500)
		div = 6;
	else
		div = 12;
	subdiv = (min + max) / div;
	while (!is_empty(a))
		psh(a, b, subdiv * i++);
	push_to_b(b, a);
}
