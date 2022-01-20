/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ubtmp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 04:11:20 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/20 14:35:37 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*copy;
	size_t	s1_len;
	int		i;

	i = 0;
	s1_len = ft_strlen(s1);
	copy = malloc(sizeof(char) * (s1_len + 1));
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char c)
{
	char	*output;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_strdup("");
	output = (char *) malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!output)
		return (0);
	i = 0;
	j = 0;
	while (s1[j])
		output[i++] = s1[j++];
	output[i++] = c;
	output[i] = 0;
	return (output);
}

void	do_operation(char *str, t_stack *a, t_stack *b)
{
	if (ft_strcmp(str, "pa") == 0)
		pa(a, 0);
	else if (ft_strcmp(str, "pb") == 0)
		pb(a, 0);
	else if (ft_strcmp(str, "sa") == 0)
		sa(a, 0);
	else if (ft_strcmp (str, "sb") == 0)
		sb(b, 0);
	else if (ft_strcmp (str, "ss") == 0)
		ss(a, b);
	else
		rotate_reverse(str, a, b);
}

void	rotate_reverse(char *str, t_stack *a, t_stack *b)
{
	if (ft_strcmp(str, "ra") == 0)
		ra(a, 0);
	else if (ft_strcmp(str, "rb") == 0)
		rb(b, 0);
	else if (ft_strcmp(str, "rra") == 0)
		rra(a, 0);
	else if (ft_strcmp (str, "rrb") == 0)
		rrb(b, 0);
	else if (ft_strcmp (str, "rr") == 0)
		rr(a, b);
	else if (ft_strcmp (str, "rrr") == 0)
		rrr(a, b);
	else
	{
		free_stack(a);
		free_stack(b);
		free(str);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
