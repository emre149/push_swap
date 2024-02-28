/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 00:14:25 by ededemog          #+#    #+#             */
/*   Updated: 2024/02/28 23:08:09 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || argc == 2 && !argv[1][0])
		return (1);
	if (argc > 2)
		ft_split(join_split(argv[1]));
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	split_to_stack(&stack_a, argv + 1, argc == 2);
}
