/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:51:43 by otlacerd          #+#    #+#             */
/*   Updated: 2025/05/22 18:46:31 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*result;

	count = 0;
	result = (unsigned char *)s;
	while (count < n)
	{
		if (result[count] == (unsigned char)c)
			return ((void *)&result[count]);
		count++;
	}
	return (NULL);
}

/*
int	main(void)
{
	const unsigned char	s[] = "teste";
	unsigned char	*result;
	int	c;
	size_t	n;

	c = 115;
	n = 2;
	result = (unsigned char *)ft_memchr(s, c, n);
	if (result == NULL)
		printf("String: %s\nSearching: %c\nFor n bytes: %d\nResult: NULL", \
			s, c, n);
	else
		printf("String: %s\nSearching: %c\nFor n bytes: %d\nResult: %c\n", \
			s, c, n, *result);
}
*/