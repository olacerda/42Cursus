/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:02:07 by otlacerd          #+#    #+#             */
/*   Updated: 2025/05/22 19:51:22 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>
// #include <string.h>

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				count;
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	count = 0;
	if (d < s)
	{
		while (count < n)
		{
			d[count] = s[count];
			count++;
		}
	}
	else
	{
		count = n;
		while (n-- > 0)
			d[n] = s[n];
	}
	return (dest);
}

/*
int	main(void)
{
	unsigned char	dest[10];
	const unsigned char	src[] = "Isso é um teste";
	size_t	n;

	n = 4;
	printf("%s", dest);
	ft_memmove(dest, src, n);
	printf("%s", dest);
}
*/

// int	main(void)
// {
// 	unsigned char	dest[10];
// 	const unsigned char	src[] = "Isso é um teste";
// 	size_t	n;

// 	n = 4;
// 	printf("%s", dest);
// 	memmove(NULL, NULL, n);
// 	printf("%s", dest);
// }