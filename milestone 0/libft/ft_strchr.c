/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:18:01 by otlacerd          #+#    #+#             */
/*   Updated: 2025/04/21 23:21:39 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		if ((unsigned char)s[count] == (unsigned char)c)
			return ((char *)&s[count]);
		count++;
	}
	if ((unsigned char)s[count] == (unsigned char)c)
		return ((char *)&s[count]);
	return (NULL);
}

/*
int	main(void)
{
	const char 	s[] = "isso e um teste";
	int	c;

	c = 'e';
	printf("String: %s\nFirst ocurrance: %s", s, ft_strchr(s, c));
}
*/