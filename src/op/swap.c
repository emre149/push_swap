/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:47:18 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/21 17:53:06 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	(*stack)->prev = tmp;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	tmp->prev = NULL;
	*stack = tmp;
}

void	sa(t_list **stack_a, bool status)
{
	swap(stack_a);
	if (!status)
		write(1, "sa\n", 3);
}

void	sb(t_list **stack_b, bool status)
{
	swap(stack_b);
	if (!status)
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b, bool status)
{
	swap(stack_a);
	swap(stack_b);
	if (!status)
		write(1, "ss\n", 3);
}
