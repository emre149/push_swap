/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:30:09 by ededemog          #+#    #+#             */
/*   Updated: 2024/02/28 23:10:11 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <stddef.h>

typedef struct s_list
{
	int				content;
	int				pos;
	int				n_price;
	bool			above_median;
	bool			smallest;
	struct s_list	*prev;
	struct s_list	*next;
	struct s_list	*target;
}					t_list;

char	*ft_strcpy(char *dest, const char *src);

char	**ft_split(const char *s, char c);

char	*join_to_split(int argc, char **argv, size_t total_len);

#endif
