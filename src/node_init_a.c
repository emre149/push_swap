/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_init_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:01:15 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/18 17:57:39 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_target_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_b;
	t_list	*target;
	long	closest_smallest_nbr;

	while (stack_a)
	{
		closest_smallest_nbr = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->content < stack_a->content
				&& current_b->content > closest_smallest_nbr)
			{
				closest_smallest_nbr = current_b->content;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_smallest_nbr == LONG_MIN)
			stack_a->target = max_of_stack(stack_b);
		else
			stack_a->target = target;
		stack_a = stack_a->next;
	}
}

static void	cost_a(t_list *stack_a, t_list *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_a)
	{
		stack_a->cost = stack_a->position;
		if (!(stack_a->above_median))
			stack_a->cost = len_a - (stack_a->position);
		if (stack_a->target->above_median)
			stack_a->cost += stack_a->target->position;
		else
			stack_a->cost += len_b - (stack_a->target->position);
		stack_a = stack_a->next;
	}
}

void	cheapest_cost(t_list *stack)
{
	long	cheapest_value;
	t_list	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	node_init_a(t_list *stack_a, t_list *stack_b)
{
	current_position(stack_a);
	current_position(stack_b);
	set_target_a(stack_a, stack_b);
	cost_a(stack_a, stack_b);
	cheapest_cost(stack_a);
}
