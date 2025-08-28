/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:11:38 by otlacerd          #+#    #+#             */
/*   Updated: 2025/04/20 19:01:12 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			count;
	unsigned char	*a;

	a = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		a[count] = '\0';
		count++;
	}
}

/*
int	main(void)
{
	char	str[] = "teste";
	int	n;

	n = 1;
	printf("%s\n", str);
	bzero(str, n);
	printf("%s", str);	
}*/