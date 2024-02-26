/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:30:09 by ededemog          #+#    #+#             */
/*   Updated: 2024/02/26 19:41:45 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>

typedef struct s_list
{
	int			*content;
	struct s_list	*next;
}	t_list;

char	*ft_strcpy(char *dest, const char *src);


#endif
