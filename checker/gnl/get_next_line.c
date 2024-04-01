/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 04:00:18 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/01 20:41:49 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static g_list	*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	read_to_stash(fd, &stash);
	if (stash == NULL)
		return (NULL);
	stash_to_line(stash, &line);
	clean(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	read_to_stash(int fd, g_list **stash)
{
	char	*buf;
	int		readed;

	readed = 1;
	while (!newline(*stash) && readed != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		readed = (int)read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && readed == 0) || readed == -1)
		{
			free(buf);
			return ;
		}
		buf[readed] = '\0';
		add(stash, buf, readed);
		free(buf);
	}
}

void	add(g_list **stash, char *buf, int already_read)
{
	int		i;
	g_list	*last_node;
	g_list	*new_node;

	i = 0;
	new_node = malloc(sizeof(g_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (already_read + 1));
	if (!new_node->content)
		return ;
	while (buf[i] && i < already_read)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (!*stash)
	{
		*stash = new_node;
		return ;
	}
	last_node = gft_lstlast(*stash);
	last_node->next = new_node;
}

void	stash_to_line(g_list *stash, char **line)
{
	int	i;
	int	j;

	j = 0;
	if (!stash)
		return ;
	line_allocation(line, stash);
	if (!*line)
		return ;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	clean(g_list **stash)
{
	g_list	*last_node;
	g_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(g_list));
	if (!stash || !clean_node)
		return ;
	clean_node->next = NULL;
	last_node = gft_lstlast(*stash);
	i = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	if (last_node->content && last_node->content[i] == '\n')
		i++;
	j = ft_strlen(last_node->content);
	clean_node->content = malloc(sizeof(char) * ((j - i) + 1));
	if (!clean_node->content)
		return ;
	j = 0;
	while (last_node->content[i])
		clean_node->content[j++] = last_node->content[i++];
	clean_node->content[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}
