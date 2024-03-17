/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:30:09 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/17 18:46:45 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>
# include <stddef.h>
// # include "../ft_printf/ft_printf.h"

typedef struct s_list
{
	int				content;
	int				pos;
	int				n_price;
	bool			above_median;
	bool			smallest;
	struct s_list	*prev;
	struct s_list	*next;
	struct s_list	*target;
}					t_list;

char		*ft_strcpy(char *dest, const char *src);

char		**ft_split(const char *s, char c);

long		ft_atol(const char *str);

void		sort_tri(t_list **stack_a);

t_list		*max_of_stack(t_list *stack);

t_list		*min_of_stack(t_list *stack);

t_list		*ft_lstlast(t_list *list);

void		split_to_stack(t_list **stack_a, char **argv);

void		sa(t_list **stack_a, bool status);

void		sb(t_list **stack_b, bool status);

void		ss(t_list **stack_a, t_list **stack_b, bool status);

void		pa(t_list **stack_a, t_list **stack_b, bool status);

void		pb(t_list **stack_a, t_list **stack_b, bool status);

#endif
