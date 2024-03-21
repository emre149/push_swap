/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:03:35 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/21 17:52:27 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rev_rotate(t_list **stack)
{
	t_list	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = ft_lstlast(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
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
