/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 00:14:25 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/08 18:06:18 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2 && !argv[1][0])
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	split_to_stack(&stack_a, argv + 1);
	if (!is_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a, false);
		else if (stack_len(stack_a) == 3)
			tri_sort(&stack_a);
		else
			turk_algo(&stack_a, &stack_b);
	}
	if (argc == 2)
		free_split(argv);
	free_stacks(&stack_a);
	return (0);
}
