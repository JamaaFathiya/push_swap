/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:14:56 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/20 04:27:33 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

/*--------Colors------- */

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define END "\033[0m"

/*---------Stack_Structs---------*/

typedef struct stack_node
{
	struct stack_node	*prev;
	struct stack_node	*next;
	int					data;
}	t_stack_node;

typedef struct stack
{
	t_stack_node	*top;
	t_stack_node	*base;
	int				size;
}	t_stack;

/*---------Stack_Functions--------*/

t_stack_node	*new_node(int data);
t_stack			*fill_stack(int n, char **str, t_stack *s);
t_stack			*init_stack(t_stack *s);
void			inhale(int data, t_stack *s);
void			push(int data, t_stack *s);
void			exhale(t_stack *s);
void			pop(t_stack *s);
int				is_empty(t_stack *s);
int				is_sorted(t_stack *s);

/*-------Parsing_Functions-------*/

void			quick_check(char	**str);
int				check_args(char **str);
int				uniq(char	**str);

/*------Secondary_Functions------*/

long long		ft_atoi(const char *nptr);
int				ft_strcmp(char *s1, char *s2);
int				is_numeric(char *str);

/*----------Instructions----------*/
void			sa(t_stack *a, int flag);
void			sb(t_stack *b, int flag);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			ra(t_stack *a, int flag);
void			rb(t_stack *b, int flag);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a, int flag);
void			rrb(t_stack *b, int flag);
void			rrr(t_stack *a, t_stack *b);

/*---------Soting_Functions---------*/

void			naive_sort(t_stack *a, t_stack *b);
void			sort(t_stack *a, t_stack *b);
void			sort_three(t_stack *s);
void			free_stack(t_stack *s);
/*--------Chunks_Functions---------*/

void			six_twelve_chunks(t_stack *a, t_stack *b, int min, int max);
void			psh(t_stack *a, t_stack *b, int subdiv);
void			push_to_b(t_stack *b, t_stack *a);
int				min_elem(t_stack *a);
int				max_elem(t_stack *b);
int				get_elem_index(t_stack *a, int elem);
int				*one_chunk(t_stack *a, int subdiv);

/*----------Bonus_Functions---------*/

void			swap_push(char *str, t_stack *a, t_stack *b);
void			rotate_reverse(char *str, t_stack *a, t_stack *b);
void			read_from_stdin(t_stack *a, t_stack *b);
char			*ft_strdup(char *s1);
char			*ft_strjoin(char *s1, char c);
#endif
