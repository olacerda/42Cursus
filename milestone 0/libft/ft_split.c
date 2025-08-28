/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:59:06 by otlacerd          #+#    #+#             */
/*   Updated: 2025/05/22 18:41:13 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>

#include "libft.h"

static void	freeall(char **str)
{
	int	word;

	word = 0;
	while (str[word] != NULL)
	{
		free(str[word]);
		word++;
	}
}

static int	countworder(char const *s, char c)
{
	int	count;
	int	words;

	count = 0;
	words = 0;
	while (s[count])
	{
		if (s[count] != c && s[count])
		{
			while (s[count] != c && s[count])
				count++;
			words++;
		}
		else
			count++;
	}
	return (words);
}

static char	*strdupper(const char *a, int index, char sep, char **str)
{
	char	*result;
	int		count;
	int		end;

	count = 0;
	end = 0;
	while (a[index + end] != sep && a[index + end])
		end++;
	result = (char *) malloc((end + 1) * sizeof(char));
	if (!result)
	{
		freeall(str);
		return (NULL);
	}
	end = index + end;
	while (index < end)
	{
		result[count] = a[index];
		index++;
		count++;
	}
	result[count] = '\0';
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**stringfinal;
	int		count;
	int		words;

	count = 0;
	words = 0;
	stringfinal = (char **) malloc((countworder(s, c) + 1) * sizeof(char *));
	if (!stringfinal)
		return (NULL);
	while (s[count])
	{
		if (s[count] != c)
		{
			stringfinal[words] = strdupper(s, count, c, stringfinal);
			if (stringfinal[words] == NULL)
				return (NULL);
			words++;
			while (s[count] != c && s[count])
				count++;
		}
		if (s[count] == c && s[count])
			count++;
	}
	stringfinal[words] = NULL;
	return (stringfinal);
}

// int	main(void)
// {
// 	char const	str[] = "isso e um teste";
// 	char	sep;
// 	char	**result;
// 	int	words;

// 	sep = ' ';
// 	words = 0;
// 	result = ft_split(str, sep);
// 	while(result[words] != NULL)
// 	{
// 		printf("Sring ---> %s\n", result[words]);
// 		words++;
// 	}
// 	if (result[words] == NULL)
// 		printf("Sring ---> %s\n", result[words]);
// 	else
// 		printf("Not a NUll");
// 	freeall(result);
// 	free(result);
// }