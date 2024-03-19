/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_init_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:24:48 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/19 17:42:02 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_target_b(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_a;
	t_list	*target;
	long	closest_smallest_nbr;

	while (stack_b)
	{
		closest_smallest_nbr = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->content > stack_b->content
				&& current_a->content < closest_smallest_nbr)
			{
				closest_smallest_nbr = current_a->content;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (closest_smallest_nbr == LONG_MAX)
			stack_b->target = min_of_stack(stack_a);
		else
			stack_b->target = target;
		stack_b = stack_b->next;
	}
}

void	node_init_b(t_list *stack_a, t_list *stack_b)
{
	current_position(stack_a);
	current_position(stack_b);
	set_target_b(stack_a, stack_b);
}
