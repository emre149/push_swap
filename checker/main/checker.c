/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:29:06 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/08 18:59:43 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../../push_swap.h"

int	check(char *ligne, t_list *stack_a, t_list *stack_b)
{
	if (ft_strcmp(ligne, "OK?") == 0)
	{
		if (is_sorted(stack_a) == false)
		{
			write(1, "KO\n", 3);
			exit(2);
		}
		else
		{
			write(1, "OK\n", 3);
			exit(1);
		}
	}
	else
		if (!interpretor(&stack_a, &stack_b, ligne))
			write(1, "Error\n", 6);
	free(ligne);
	ligne = NULL;
	return (0);
}

int	main(int argc, char **argv)
{
	char	*ligne;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	ligne = get_next_line(0);
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	split_to_stack(&stack_a, argv + 1);
	if (stack_len(stack_a) < 2)
		return (1);
	while (ligne != NULL)
	{
		check(ligne, stack_a, stack_b);
		ligne = get_next_line(0);
	}
	if (argc == 2)
		free_split(argv);
	free_stacks(&stack_a);
	return (0);
}
