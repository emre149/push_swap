/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:14:17 by ededemog          #+#    #+#             */
/*   Updated: 2024/02/28 17:08:13 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../push_swap.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	j;
	int	status;

	i = 0;
	j = 0;
	status = 0;
	while (s[i])
	{
		if (s[i] != c && status == 0)
		{
			status = 1;
			j++;
		}
		else if (s[i] == c)
			status = 0;
		i++;
	}
	return (j);
}

int	mallocizer(char **words_v, int pos, size_t len)
{
	int	i;

	i = 0;
	words_v[pos] = malloc(len);
	if (!words_v[pos])
	{
		while (i < pos)
			free(words_v[i++]);
		free(words_v);
		return (1);
	}
	return (0);
}

int    append(char **words_v, const char *s, char c)
{
	size_t	len;
	int	pos;
	const char *start;

	pos = 0;
	start = s;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		start = s;
		while (*s != c && *s)
		{
			++len;
			++s;
		}
		if (len)
		{
			if (mallocizer(words_v, pos, len + 1))
				return (1);
			ft_strlcpy(words_v[pos], start, len + 1);
			pos++;
		}
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	size_t	words;
	char	**words_v;

	if (!s)
		return (NULL);
	words = 0;
	words = count_words(s, c);
	words_v = malloc((words + 1) * sizeof(char *));
	if (!words_v)
		return (NULL);
	words_v[words] = NULL; // EOL
	if (append(words_v, s, c))
		return (NULL);
	return (words_v);
}

int	main()
{
	char	*s = " Bonjour     Emre. ca va bien ???? ";
	char	**v = ft_split(s, ' ');

	while (*v)
	printf("%s\n", *v++);
	
	return (0);
}
