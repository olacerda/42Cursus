/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:33:43 by otlacerd          #+#    #+#             */
/*   Updated: 2025/04/18 17:56:54 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n && (s1[count] != '\0' || s2[count] != '\0'))
	{
		if ((unsigned const char)s1[count] != (unsigned const char)s2[count])
			return ((unsigned const char)s1[count] \
				- (unsigned const char)s2[count]);
		count++;
	}
	return (0);
}

/*
int	main(void)
{
	const char	s1[] = "te";
	const char	s2[] = "tem";
	size_t	n;

	n = 3;
	printf("%d", ft_strncmp(s1, s2, n));
}
*/