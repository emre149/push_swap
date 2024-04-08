/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpretation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:18:37 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/08 17:04:57 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "../push_swap.h"


static bool handle_swap(t_list **stack_a, t_list **stack_b, char *ligne)
{
    if (ft_strcmp(ligne, "pa") == 0)
	{
        pa(stack_a, stack_b, true);
		return (true);	
	}
    else if (ft_strcmp(ligne, "pb") == 0)
	{
        pb(stack_b, stack_a, true);
		return (true);
	}
	return (false);
}

static bool handle_rotate(t_list **stack_a, t_list **stack_b, char *ligne)
{
    if (ft_strcmp(ligne, "ra") == 0)
	{
        ra(stack_a, true);
		return (true);
	}
    else if (ft_strcmp(ligne, "rb") == 0)
	{
        rb(stack_b, true);
		return (true);
	}
    else if (ft_strcmp(ligne, "rr") == 0)
	{
        rr(stack_a, stack_b, true);
		return (true);
	}
	return (false);
}

static bool handle_reverse_rotate(t_list **stack_a, t_list **stack_b, char *ligne)
{
    if (ft_strcmp(ligne, "rra") == 0)
	{
        rra(stack_a, true);
		return (true);
	}
    else if (ft_strcmp(ligne, "rrb") == 0)
	{
        rrb(stack_b, true);
		return (true);
	}
    else if (ft_strcmp(ligne, "rrr") == 0)
	{
        rrr(stack_a, stack_b, true);
		return (true);
	}
	return (false);
}

static bool handle_push(t_list **stack_a, t_list **stack_b, char *ligne)
{
    if (ft_strcmp(ligne, "sa") == 0)
	{
        sa(stack_a, true);
		return (true);
	}
    else if (ft_strcmp(ligne, "sb") == 0)
	{
        sb(stack_b, true);
		return (true);
	}
    else if (ft_strcmp(ligne, "ss") == 0)
	{
        ss(stack_a, stack_b, true);
		return (true);
	}
	return (false);
}

int interpretor(t_list **stack_a, t_list **stack_b, char *ligne)
{
    if (handle_swap(stack_a, stack_b, ligne)) return true;
    if (handle_rotate(stack_a, stack_b, ligne)) return true;
    if (handle_reverse_rotate(stack_a, stack_b, ligne)) return true;
    if (handle_push(stack_a, stack_b, ligne)) return true;

    return false;
}
