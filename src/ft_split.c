/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:14:17 by ededemog          #+#    #+#             */
/*   Updated: 2024/02/26 19:47:26 by ededemog         ###   ########.fr       */
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

int main() {
    char test_string1[] = "Ceci est un test";
    char test_string2[] = "  Ceci est un test avec espaces multiples";
    char test_string3[] = "Ceci,est,un,test,avec,virgules";
    char test_string4[] = "Ceci est un test avec des caractères spéciaux !@#$%^&*()";

    char delimiter1 = ' ';
    char delimiter2 = ',';

    printf("Test  1: Nombre de mots dans \"%s\" avec l'espace comme séparateur : %d\n", test_string1, count_words(test_string1, delimiter1));
    printf("Test  2: Nombre de mots dans \"%s\" avec l'espace comme séparateur : %d\n", test_string2, count_words(test_string2, delimiter1));
    printf("Test  3: Nombre de mots dans \"%s\" avec la virgule comme séparateur : %d\n", test_string3, count_words(test_string3, delimiter2));
    printf("Test  4: Nombre de mots dans \"%s\" avec l'espace comme séparateur : %d\n", test_string4, count_words(test_string4, delimiter1));

    return  0;
}

/*
int	main(int argc, char const **argv)
{
	char str[256];
	ft_strcpy(str, argv[1]);
	char	delimiter;
	int	words;

	delimiter = ' ';
	words = count_words(str, delimiter);
	if (argc > 2)
		printf("nombres de mots : %d", words);
	return (0);
}
*/
/*
char	**ft_split(char const *s, char c)
{
	
}
*/
