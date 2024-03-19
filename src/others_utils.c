/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:10:05 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/19 17:23:25 by ededemog         ###   ########.fr       */
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > 0 && (s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	min_on_top(t_list **stack_a)
{
	while ((*stack_a)->content != min_of_stack(*stack_a)->content)
	{
		if (min_of_stack(*stack_a)->above_median)
			ra(stack_a, false);
		else
			rra(stack_a, false);
	}
}

