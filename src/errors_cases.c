/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:57:55 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/20 14:53:08 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error_syntax(char *str_n) //Define a funtion to handle syntax errors, and returns `1` for `error` should any of the following conditions are met
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9'))) //Check if the first character of the input string does not contain a sign or a digit
		return (1);
	if ((*str_n == '+'
			|| *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9')) //Check if the first character of the input string contains a sign, but the second character does not contain a digit
		return (1);
	while (*++str_n) //If the error conditions above are passed, pre-increment to point to the next character in the string, and loop until the end of the string is reached
	{
		if (!(*str_n >= '0' && *str_n <= '9')) //Check if the next character in the string is not a digit
			return (1);
	}
	return (0);
}

int	same_n(t_list *stack_a, int n)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->content == n)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	free_stacks(t_list **stack)
{
	t_list	*tmp;
	t_list	*actual;

	if (!stack)
		return ;
	actual = *stack;
	while (actual)
	{
		tmp = actual->next;
		actual->content = 0;
		free(actual);
		actual = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_list **stack_a)
{
	free_stacks(stack_a);
	write(1, "Error\n", 6);
	exit(1);
}
