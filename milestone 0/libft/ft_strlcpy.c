/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:24:20 by otlacerd          #+#    #+#             */
/*   Updated: 2025/04/21 23:37:12 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	srcsize;

	count = 0;
	srcsize = 0;
	while (src[srcsize] != '\0')
		srcsize++;
	if (size == 0)
		return (srcsize);
	while (count < (size - 1) && src[count] != '\0')
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (srcsize);
}

/*
int	main(void)
{
	char	dst[4];
	const char	src[] = "isso e um teste";
	size_t	size;

	size = 4;
	printf("string antes: %s\n", dst);
	ft_strlcpy(dst, src, size);
	printf("string depois: %s", dst);
}
*/