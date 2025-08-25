/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:15:48 by otlacerd          #+#    #+#             */
/*   Updated: 2025/05/22 19:23:01 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
*/

#include "libft.h"

static int	slen(const char *a)
{
	int	count;

	count = 0;
	while (a[count] != '\0')
		count++;
	return (count);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	count;
	char			*result;

	count = 0;
	if (!s || !f)
		return (NULL);
	result = (char *) malloc(slen(s) + 1 * sizeof(char));
	if (!result)
		return (NULL);
	while (s[count] != '\0')
	{
		result[count] = f(count, s[count]);
		count++;
	}
	result[count] = '\0';
	return (result);
}

/* 
static char	uppercaser(unsigned int a, char b)
{
	a = b;
	if (b >= 97 && b <= 122)
		b = b - 32;
	return (b);
} */
// int	main(void)
// {
// 	char	teste[] = "isso e um teste";
// 	char	*result = ft_strmapi(teste, uppercaser);

// 	printf("%s\n", teste);
// 	printf("%s\n", result);
// 	free(result);
// }