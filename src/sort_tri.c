/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:31:56 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/17 16:16:06 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_tri(t_list **stack_a)
{
	t_list	*my_big_node;

	my_big_node = max_of_stack(*stack_a);
	if (my_big_node == *stack_a)
		ra(stack_a, false);
	else if ((*stack_a)->next == my_big_node)
		rra(stack_a, false);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a, false);
}
