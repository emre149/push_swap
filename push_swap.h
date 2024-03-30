/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:30:09 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/30 15:24:50 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*INCLUDES*/

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>
# include <stddef.h>
// # include "../ft_printf/ft_printf.h"

/*STACK STRUCT*/

typedef struct s_list
{
	int				content;
	int				position;
	int				cost;
	bool			above_median;
	bool			smallest;
	bool			cheapest;
	struct s_list	*prev;
	struct s_list	*next;
	struct s_list	*target;
}					t_list;

/*OPERATIONS*/

void		sa(t_list **stack_a, bool status);
void		sb(t_list **stack_b, bool status);
void		ss(t_list **stack_a, t_list **stack_b, bool status);
void		pa(t_list **stack_a, t_list **stack_b, bool status);
void		pb(t_list **stack_a, t_list **stack_b, bool status);
void		ra(t_list **stack_a, bool status);
void		rb(t_list **stack_b, bool status);
void		rr(t_list **stack_a, t_list **stack_b, bool status);
void		rra(t_list **stack_a, bool status);
void		rrb(t_list **stack_b, bool status);
void		rrr(t_list **stack_a, t_list **stack_b, bool status);

/*ERRORS CASES*/

int			error_syntax(char *str_n);
int			same_n(t_list *stack_a, int n);
void		free_stacks(t_list **stack);
void		free_errors(t_list **stack_a);

/*ALGOS*/

void		turk_algo(t_list **stack_a, t_list **stack_b);
void		tri_sort(t_list **stack_a);

/*STACKS UTILS*/

int			stack_len(t_list *stack);
t_list		*max_of_stack(t_list *stack);
t_list		*min_of_stack(t_list *stack);
t_list		*ft_lstlast(t_list *list);
bool		is_sorted(t_list *stack);

/*NODE INIT*/

void		node_init_a(t_list *stack_a, t_list *stack_b);
void		node_init_b(t_list *stack_a, t_list *stack_b);
void		current_position(t_list *stack);
void		cheapest_cost(t_list *stack);
void		ready_to_push(t_list **stack, t_list *top, char stack_name);
t_list		*get_cheapest(t_list *stack);


/*STACKS INIT*/

void		split_to_stack(t_list **stack_a, char **argv);
long		ft_atol(const char *str);
char		**ft_split(char *s, char c);
void		min_on_top(t_list **stack_a);
void		head_min(t_list **stack_a);
#endif
