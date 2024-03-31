/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:10:03 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/31 16:35:19 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	cheap_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		r_rotate_both(stack_a, stack_b, cheapest);
	ready_to_push(stack_a, cheapest, 'a');
	ready_to_push(stack_b, cheapest->target, 'b');
	pb(stack_b, stack_a, false);
}

static void	cheap_b_to_a(t_list **stack_a, t_list **stack_b)
{
	ready_to_push(stack_a, (*stack_b)->target, 'a');
	pa(stack_a, stack_b, false);
}

static void	head_min(t_list **stack_a)
{
	while ((*stack_a)->content != min_of_stack(*stack_a)->content)
	{
		if (min_of_stack(*stack_a)->above_median)
			ra(stack_a, false);
		else
			rra(stack_a, false);
	}
}

void	turk_algo(t_list **stack_a, t_list **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !is_sorted(*stack_a))
		pb(stack_b, stack_a, false);
	if (len_a-- > 3 && !is_sorted(*stack_a))
		pb(stack_b, stack_a, false);
	while (len_a-- > 3 && !is_sorted(*stack_a))
	{
		node_init_a(*stack_a, *stack_b);
		cheap_a_to_b(stack_a, stack_b);
	}
	tri_sort(stack_a);
	while (*stack_b)
	{
		node_init_b(*stack_a, *stack_b);
		cheap_b_to_a(stack_a, stack_b);
	}
	current_position(*stack_a);
	head_min(stack_a);
}
