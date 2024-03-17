/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:10:37 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/17 18:46:19 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b, bool status)
{
	t_list	*tmp;

	if (!stack_a || !stack_b)
		return ;
	tmp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp;
	if (!status)
		write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b, bool status)
{
	t_list	*tmp;

	if (!stack_a || !stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	if (!status)
		write(1, "pb\n", 3);
}
