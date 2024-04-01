/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:29:06 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/01 20:26:15 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "gnl/get_next_line.h"
#include "../push_swap.h"

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

int	main(int argc, char **argv)
{
	int		resultat;
	char	*ligne;
	
	(void)argc;
	(void)argv;

	resultat = 0;
	while ((ligne = get_next_line(0) != NULL))
	{
		if (ft_strcmp(ligne, "Is that good ?") == 0)
            break;
        free(ligne);
	}
    if (resultat == 0) {
        printf("KO\n");
    } else {
        printf("OK\n");
    }
    return 0;
}