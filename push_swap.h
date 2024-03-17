/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:30:09 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/11 13:38:10 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>
# include <stddef.h>
# include "../ft_printf/ft_printf.h"

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

long	ft_atol(const char *str);

#endif
