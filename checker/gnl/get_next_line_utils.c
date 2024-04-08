/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 04:00:29 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/08 16:43:40 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline(gt_list *stash)
{
	int		i;
	gt_list	*current;

	if (stash == NULL)
		return (0);
	current = gft_lstlast(stash);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

gt_list	*gft_lstlast(gt_list *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}

void	line_allocation(char **line, gt_list *stash)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

/* Frees the entire stash. */

void	free_stash(gt_list *stash)
{
	gt_list	*current;
	gt_list	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
