/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:10:05 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/18 19:00:22 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*max_of_stack(t_list *stack)
{
	t_list	*max_node;
	long	max_min;

	max_min = LONG_MIN;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->content > max_min)
		{
			max_min = stack->content;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_list	*min_of_stack(t_list *stack)
{
	t_list	*min_node;
	long	min_max;

	min_max = LONG_MAX;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->content < min_max)
		{
			min_max = stack->content;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

