/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:19:20 by otlacerd          #+#    #+#             */
/*   Updated: 2025/04/18 17:29:59 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>

int	ft_strlen(char *a)
{
	int	count;

	count = 0;
	while (a[count] != '\0')
	{
		count++;
	}
	return (count);
}
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	srcsize;
	size_t	dstsize;

	count = 0;
	srcsize = 0;
	dstsize = ft_strlen(dst);
	while (src[srcsize] != '\0')
	{
		srcsize++;
	}
	if (dstsize >= size)
		return (srcsize + size);
	while (((dstsize + count) < (size -1)) && src[count] != '\0')
	{
		dst[dstsize + count] = src[count];
		count++;
	}
	dst[dstsize + count] = '\0';
	return (dstsize + srcsize);
}

/*
int	main(void)
{
	char	dst[5] = "12";
	const char	src[] = "345";
	size_t	size;

	size = 5;
	printf("dst antes: %s\n", dst);
	ft_strlcat(dst, src, size);
	printf("dst antes: %s", dst);	
}
*/