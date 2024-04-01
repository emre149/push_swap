/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 04:00:05 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/01 20:41:22 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct g_list
{
	char			*content;
	struct g_list	*next;
}	g_list;

char	*get_next_line(int fd);

void	read_to_stash(int fd, g_list **stash);

g_list	*gft_lstlast(g_list *list);

int		newline(g_list *stash);

void	stash_to_line(g_list *stash, char **line);

void	line_allocation(char **line, g_list *stash);

int		ft_strlen(const char *str);

void	add(g_list **stash, char *buf, int already_read);

void	free_stash(g_list *stash);

void	clean(g_list **stash);

#endif