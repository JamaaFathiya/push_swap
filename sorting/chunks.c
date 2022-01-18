/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:20:14 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/18 16:13:44 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    get_elem_index(t_stack a, int elem)
{
    int    index;

    index = 0;
    if (!a.top)
        return (-1);
    while (a.top && a.top->data != elem)
    {
        a.top = a.top->bellow;
        index++;
    }
    return (index);
}

int	min_elem(t_stack *s)
{
	int				min;
	t_stack_node	*tmp;

	tmp = s->top;
	min = s->top->data;
	while(tmp)
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
	while(tmp)
	{
		tmp = tmp->next;
		if (tmp->data > max)
			max = tmp->data;
	}
	return (max);
}

void	sort(t_stack *a,	t_stack *b)
{
	int	min;
	int	max;

	min = min_elem(a);
	max = max_elem(a);
	if (s->size < 100)
		naive_sort(a, b);
	else if (s->size >= 100 && s->size < 400)
		six_chunks(a, b, min , max);
	else if (s->size >= 400)
		twelve_chunks(a, b, min , max);
}
