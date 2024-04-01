/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:36:17 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/01 20:40:40 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "gnl/get_next_line.h"
#include "../push_swap.h"

int	ft_strcmp(const char *first, const char *second)
{
	int	i;

	i = 0;
	while (first[i] != '\0' && second[i] != '\0')
	{
		if (first[i] != second[i])
			return (first[i] - second[i]);
		i++;
	}
	if (first[i] == '\n' && second[i] == '\0')
		return 0;
	if (first[i] == '\0' && second[i] == '\n')
		return 0;
	return (first[i] - second[i]);
}


// void	checker(t_list **stack_a, t_list **stack_b, char *ligne)
// {
// 	int	state;
// 	int	resultat;

// 	resultat = 0;
// 	while ((ligne = get_next_line(0) != NULL))
// 	{
// 		state = interpretor(stack_a, stack_b, ligne);
// 		if (!state)
// 			printf("Error, not an operation");
// 		if (ft_strcmp(ligne, "Is that good ?") == 0)
//             break;
//         free(ligne);
// 	}
//     if (resultat == 0) {
//         printf("KO\n");
//     } else {
//         printf("OK\n");
//     }
//     return 0;
// }

// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	(void)argv;

// 	t_list	*stack_a;
// 	t_list	*stack_b;
// 	char	*ligne;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	ligne = NULL;
// 	checker(stack_a, stack_b, ligne);
// 	return (0);
// }