/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:54:52 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/18 15:02:00 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ra(t_list **stack_a, bool status)
{
	t_list	*tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = ft_lstlast(*stack_a);
	(*stack_a)->next = tmp;
	*stack_a = tmp->next;
	tmp->next = NULL;
	if (!status)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, bool status)
{
	t_list	*tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = ft_lstlast(*stack_b);
	(*stack_b)->next = tmp;
	*stack_b = tmp->next;
	tmp->next = NULL;
	if (!status)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, bool status)
{
	ra(stack_a, status);
	rb(stack_b, status);
	if (!status)
		write(1, "rr\n", 3);
}

