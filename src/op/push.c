/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:10:37 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/31 17:07:07 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	push(t_list **dest, t_list **src)
{
	t_list	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

void	pa(t_list **stack_a, t_list **stack_b, bool status)
{
	push(stack_a, stack_b);
	if (!status)
		write(1, "pa\n", 3);
}

void	pb(t_list **stack_b, t_list **stack_a, bool status)
{
	push(stack_b, stack_a);
	if (!status)
		write(1, "pb\n", 3);
}
