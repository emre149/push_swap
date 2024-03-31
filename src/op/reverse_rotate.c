/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:03:35 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/30 18:36:02 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	rev_rotate(t_list **stack)
{
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_list **stack_a, bool status)
{
	rev_rotate(stack_a);
	if (!status)
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b, bool status)
{
	rev_rotate(stack_b);
	if (!status)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b, bool status)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (!status)
		write(1, "rrr\n", 4);
}

void	r_rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	while (*stack_b != cheapest->target && *stack_a != cheapest)
		rrr(stack_a, stack_b, false);
	current_position(*stack_a);
	current_position(*stack_b);
}
