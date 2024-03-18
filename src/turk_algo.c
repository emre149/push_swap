/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:10:03 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/18 18:49:23 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	while (*stack_b != cheapest->target && *stack_a != cheapest)
		rr(stack_a, stack_b, false);
	current_position(*stack_a);
	current_position(*stack_b);
}

static void	r_rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	while (*stack_b != cheapest->target && *stack_a != cheapest)
		rrr(stack_a, stack_b, false);
	current_position(*stack_a);
	current_position(*stack_b);
}

static void	cheap_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		r_rotate_both(stack_a, stack_b, cheapest);
	ready_to_push(stack_a, cheapest, 'stack_a');
	ready_to_push(stack_b, cheapest->target, 'stack_b');
	pb(stack_b, stack_a, false);
}

void	turk_algo(t_list **stack_a, t_list **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (--len_a > 3 && !is_sorted(*stack_a))
		pb(stack_b, stack_a, false);
	while (--len_a > 3 && !is_sorted(*stack_a))
	{
		node_init_a(*stack_a, *stack_b);
		cheap_a_to_b(stack_a, stack_b);
	}
	sort_tri(stack_a);
	while (*stack_b)
	{
		node_init_b(*stack_a, *stack_b);
		cheap_b_to_a(stack_a, stack_b);
	}
	current_position(*stack_a);
	head_min(stack_a);
}
