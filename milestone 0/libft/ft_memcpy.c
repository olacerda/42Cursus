/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:34:29 by otlacerd          #+#    #+#             */
/*   Updated: 2025/05/28 19:26:50 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				count;

	d = dest;
	s = src;
	count = 0;
	while (count < n)
	{
		d[count] = s[count];
		count++;
	}
	return (dest);
}

// int	main(void)
// {
// 	unsigned char	dest[10];
// 	const unsigned char	src[] = "teste";
// 	int	n;

// 	n = 2;
// 	ft_memcpy(dest, src, n);
// 	printf("%s", dest);
// }