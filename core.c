/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:32:49 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/14 13:07:07 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char ** av)
{
    t_stack *a;
    t_stack *b;
    
    a = NULL;
    b = NULL;
    quick_check(av);
    a = fill_stack(ac, av, a);
    b = fill_stack(ac, av, b);
    printf("%s STACK A\n%s", YELLOW, END);
    print(a);
    printf("%s STACK B\n%s", GREEN, END);
    print(b);
    printf("%s----AFTER----%s\n",RED,END);
    rrr(a, b);
    printf("%s STACK A\n%s", YELLOW, END);
    print(a);
    printf("%s STACK B\n%s", GREEN, END);
    print(b);
    
    return (0);
}