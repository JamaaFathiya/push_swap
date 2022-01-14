/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_implementation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:08:36 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/14 11:35:44 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_stack *s)
{
	return (s->top == NULL);
}

int	is_sorted(t_stack *s)
{
	t_stack_node	*tmp;

	tmp = s->top;
	while (tmp->next)
	{
		if (tmp > tmp->next)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_stack	*init_stack(t_stack *s)
{
	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->top = NULL;
	s->base = NULL;
	s->size = 0;
	return (s);
}

t_stack_node	*new_node(int data)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_stack	*fill_stack(int n, char **str, t_stack *s)
{
	s = init_stack(s);
	while (--n)
		push(ft_atoi(str[n]), s);
	return (s);
}
