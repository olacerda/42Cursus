/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:25:26 by otlacerd          #+#    #+#             */
/*   Updated: 2025/05/22 18:57:40 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	if ((unsigned char)s[count] == (unsigned char)c)
		return ((char *)&s[count]);
	count--;
	while (count >= 0)
	{
		if ((unsigned char)s[count] == (unsigned char)c)
			return ((char *)&s[count]);
		count--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	s[] = "isso e um teste";
// 	int	c;

// 	c = 101;
// 	printf("String: %s\nFirst ocurrence: %s\n", s, ft_strrchr(s, c));	
// }