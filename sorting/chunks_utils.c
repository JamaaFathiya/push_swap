/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:45:05 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/19 11:51:34 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	sort_three(t_stack	*s)
{
	int	min; 

	min = stack_min(s);
	if (min == 1)
		if (s->top->data > s->base->data)
			ra(s, 1);
		else
			sa(s, 1);
	else if (min == 2)
		if (s->top->data > s->top->next->data)
		{
			sa(s, 1);
			rra(s, 1);
		}
		else
			rra(s, 1);
	else
	{
		sa(s, 1);
		ra(s, 1);
	}

}

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

	while (!is_sorted(a))
	{

		if(a->size == 3)
			sort_three(a);
		else
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
	}
	while (!is_empty(b))
		pa(a, b);
}

   */
int	*one_chunk(t_stack *a, int	subdiv)
{
	int	i;
	int	j;
	t_stack_node	*tmp_up;
	t_stack_node 	*tmp_down;


	i = 0;
	j = a->size - 1;
	tmp_up = a->top;
	tmp_down = a->base;
	while (i++ < j-- && !is_empty(a))
	{
		if (tmp_up->data < subdiv)
			return (&(tmp_up->data));
		else if (tmp_down->data)
			return (&(tmp_down->data));
			tmp_up = tmp_up->next;
			tmp_down = tmp_down->prev;
	}
	return (NULL);

}

void	psh(t_stack *a, t_stack *b, int index)
{
	int	i;

	i = 0;
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

void	six_chunks(t_stack *a, t_stack *b, int min, int max)
{

	int	subdiv;
	int	*elem;

	subdiv = min + max / 6;
	//	while (!is_sorted(a))
	//	{
			elem = one_chunk(a, subdiv);
	//		while (elem)
	//		{
	printf("in the chunk : %d\n\n", *elem);
	printf("STACK A\n");
	print(a);
	printf("index :%d\n", get_elem_index(*a, *elem));
				psh(a, b, get_elem_index(*a, *elem));
	//		}
	//	}
	printf("STACK B\n");
	print(b);
	printf("STACK A\n");
	print(a);
}

/*
void	twelve_chunks(t_stack *a, t_stack *b, int min, int max)
{
}*/
