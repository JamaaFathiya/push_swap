/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:45:05 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/16 15:43:11 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	sort_three(t_stack	*s)
{

}
*/

int	stack_min(t_stack *s)
{
	int				min;
	int				index;
	int				tmp_index;
	t_stack_node	*tmp_node;

	if (is_empty(s))
		return (-1);
	index = 0;
	tmp_index = 0;
	min = s->top->data;
	tmp_node = s->top->next;
	while (tmp_node)
	{
		tmp_index++;
		if (tmp_node->data < min)
		{
			min = tmp_node->data;
			index = tmp_index;
		}
		tmp_node = tmp_node->next;
	}
	return (index);
}

void	naive_sort(t_stack *a, t_stack *b)
{
	int	index;
	int	i;

	//if(a->size == 3)
	//	sort_three(a);
	while (!is_sorted(a))
	{
		i = 0;
		index = stack_min(a);
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
	while (!is_empty(b))
		pa(a, b);
}
