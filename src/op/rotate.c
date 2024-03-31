/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:54:52 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/31 17:09:27 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
/*
static void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = ft_lstlast(*stack);
	(*stack)->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
}
*/

static void	rotate(t_list **stack)
{
	t_list	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = ft_lstlast(*stack); 
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_list **stack_a, bool status)
{
	rotate(stack_a);
	if (!status)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, bool status)
{
	rotate(stack_b);
	if (!status)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, bool status)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!status)
		write(1, "rr\n", 3);
}

void	rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	while (*stack_b != cheapest->target && *stack_a != cheapest)
		rr(stack_a, stack_b, false);
	current_position(*stack_a);
	current_position(*stack_b);
}
