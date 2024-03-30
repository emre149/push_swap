/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:54:52 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/30 16:02:59 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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

