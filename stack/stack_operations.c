/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:15:22 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/19 21:50:22 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int data, t_stack *s)
{
	t_stack_node	*temp;

	temp = new_node(data);
	if (is_empty(s))
	{
		s->base = temp;
		s->base = temp;
	}
	else
	{
		temp->next = s->top;
		s->top->prev = temp;
		temp->prev = NULL;
	}
	s->top = temp;
	s->size++;
}

void	pop(t_stack *s)
{
	t_stack_node	*tmp;

	if (!is_empty(s))
	{
		tmp = s->top;
		if (s->size == 1)
		{
			s->top = NULL;
			s->base = NULL;
		}
		else
		{
			tmp->next->prev = NULL;
			s->top = tmp->next;
		}
		s->size--;
		free(tmp);
	}
}

void	inhale(int data, t_stack *s)
{
	t_stack_node	*tmp;

	tmp = new_node(data);
	if (is_empty(s))
		s->top = tmp;
	else
	{
		tmp->prev = s->base;
		s->base->next = tmp;
	}
	s->size++;
	s->base = tmp;
}

void	exhale(t_stack *s)
{
	t_stack_node	*tmp;

	if (!is_empty(s))
	{
		tmp = s->base;
		if (s->size == 1)
			s->top = NULL;
		else
		{
			tmp->prev->next = NULL;
		}
		s->base = tmp->prev;
		free(tmp);
		s->size--;
	}
}

void	print(t_stack *s)
{
	t_stack_node	*n;

	n = s->top;
	while (n != NULL)
	{
		printf("%d\n", n->data);
		n = n->next;
	}
}
