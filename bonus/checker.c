/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 03:55:37 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/20 14:26:20 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	read_from_stdin(t_stack *a, t_stack *b)
{
	char	*input;
	char	c;

	input = NULL;
	while (read(0, &c, 1))
	{
		if (c == '\n')
		{
			do_operation(input, a, b);
			free(input);
			input = ft_strdup("");
		}
		else
			input = ft_strjoin(input, c);
	}
	free(input);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		exit (1);
	a = fill_stack(ac, av, a);
	b = init_stack(b);
	quick_check(av);
	read_from_stdin(a, b);
	if (is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(a);
	free_stack(b);
	return (0);
}
