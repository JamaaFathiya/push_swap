/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:19:27 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/20 14:30:34 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	uniq(char	**str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		if (str[i][0] == '\0')
			return (0);
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_args(char **str)
{
	int			i;
	long long	data;

	i = 1;
	while (str[i])
	{
		if (!is_numeric(str[i]))
			return (0);
		data = ft_atoi(str[i]);
		if (data < INT_MIN || data > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

void	quick_check(char	**str)
{
	if (!check_args(str) || !uniq(str))
	{
		write (1, "Error\n", 6);
		exit (1);
	}
}
