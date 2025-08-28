/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:11:42 by otlacerd          #+#    #+#             */
/*   Updated: 2025/05/22 00:04:09 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	count;
	size_t	size;

	if (!s)
		return (NULL);
	size = 0;
	while (s[size])
		size++;
	if ((start > size))
		return (ft_strdup(""));
	if ((start + len) > size)
		len = size - start;
	sub = (char *) malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	count = 0;
	while (count < len)
	{
		sub[count] = s[start + count];
		count++;
	}
	sub[count] = '\0';
	return (sub);
}

// int	main(void)
// {
// 	char const	s[] = "1234A567";
// 	unsigned int	start;
// 	size_t	len;
// 	char	*teste;

// 	start = 0;
// 	len = 1;
// 	teste = ft_substr(s, start, len);
// 	printf("Substring: %s", teste);
// 	free(teste);
// }