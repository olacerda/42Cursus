/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:40:21 by otlacerd          #+#    #+#             */
/*   Updated: 2025/04/18 17:31:38 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*result;

	result = s;
	count = 0;
	while (count < n)
	{
		result[count] = (unsigned char)c;
		count++;
	}
	return (s);
}

/*
int	main(void)
{
	char	s[] = "teste";
	int	c;
	size_t	n;
	void	*teste;
	void	*result;

	c = 90;
	n = 2;
	result = ft_memset(s, c, n);
	printf("%s", result);
}
*/