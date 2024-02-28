/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:07:52 by ededemog          #+#    #+#             */
/*   Updated: 2024/02/28 23:06:36 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static size_t	total_len(int argc, char **argv)
{
	int			i;
	size_t			total_len;

	i = 0;
	total_len = 0;
	while (i < argc)
	{
		total_len += ft_strlen(argv[i]);
		if (i < argc - 1)
			total_len++;
		i++;
	}
	return (total_len);
}

char	*join(int argc, char **argv, size_t total_len)
{
	char		*new;
	char		*actual_pos;
	int		i;
	size_t		len;

	i = 1;
	new = (char *)malloc(total_len + 1);
	if (!new)
		return (NULL);
	actual_pos = new;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		ft_strncpy(actual_pos, argv[i], len);
		actual_pos += len;
		if (i < argc - 1)
		{
			*actual_pos = ' ';
			actual_pos++;
		}
		i++;
	}
	*actual_pos = '\0';
	return (new);
}
