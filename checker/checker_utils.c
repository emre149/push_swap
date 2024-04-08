/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:36:17 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/08 18:27:03 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (0);
	if (first[i] == '\0' && second[i] == '\n')
		return (0);
	return (first[i] - second[i]);
}
