/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:37:40 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/17 16:51:16 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstlast(t_list *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}

long	ft_atol(const char *str)
{
	int			i;
	long		nb;
	long		sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] && str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

static void	add_node(t_list **stack, int nb)
{
	t_list	*node;
	t_list	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->next = NULL;
	node->content = nb;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_lstlast(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	split_to_stack(t_list **stack_a, char **argv)
{
	int		i;
	long	nb;

	i = 0;
	while (argv[i])
	{
		if (syntax_errors(argv[i]))
			free_errors(stack_a);
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			free_errors(stack_a);
		if (same_n(*stack_a, (int)nb))
			free_errors(stack_a);
		add_node(stack_a, (int)nb);
		i++;
	}
}
