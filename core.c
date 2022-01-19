/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:32:49 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/19 23:32:22 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *s)
{
	t_stack_node	*tmp;

	tmp = s->top;
	while (tmp)
	{
		free(tmp);
		tmp = tmp->next;
	}
	free(s);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	quick_check(av);
	a = fill_stack(ac, av, a);
	b = init_stack(b);
	sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
