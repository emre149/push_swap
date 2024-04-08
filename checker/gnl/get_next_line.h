/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 04:00:05 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/08 18:26:06 by ededemog         ###   ########.fr       */
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
}	t_listt;

char	*get_next_line(int fd);

void	read_to_stash(int fd, t_listt **stash);

t_listt	*gft_lstlast(t_listt *list);

int		newline(t_listt *stash);

void	stash_to_line(t_listt *stash, char **line);

void	line_allocation(char **line, t_listt *stash);

int		ft_strlen(const char *str);

void	add(t_listt **stash, char *buf, int already_read);

void	free_stash(t_listt *stash);

void	clean(t_listt **stash);

#endif