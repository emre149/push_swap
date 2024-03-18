/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:03:35 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/18 15:28:16 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rra(t_list **stack_a, bool status)
{
	t_list	*last_node;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last_node = ft_lstlast(*stack_a);
	last_node->prev->next = NULL;
	last_node->next = *stack_a;
	last_node->prev = NULL;
	*stack_a = last_node;
	if (!status)
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b, bool status)
{
	t_list	*last_node;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last_node = ft_lstlast(*stack_b);
	last_node->prev->next = NULL;
	last_node->next = *stack_b;
	last_node->prev = NULL;
	*stack_b = last_node;
	if (!status)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b, bool status)
{
	rra(stack_a, status);
	rrb(stack_b, status);
	if (!status)
		write(1, "rrr\n", 4);
}

