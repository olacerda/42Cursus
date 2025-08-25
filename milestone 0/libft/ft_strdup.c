/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 01:58:44 by otlacerd          #+#    #+#             */
/*   Updated: 2025/05/22 18:40:30 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <stdlib.h>
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	result = (char *) malloc((count + 1) * sizeof(char));
	if (!result)
		return (NULL);
	count = 0;
	while (s[count] != '\0')
	{
		result[count] = s[count];
		count++;
	}
	result[count] = '\0';
	return (result);
}

// int	main(void)
// {
// 	const char	s[] = "teste";
// 	char *result;

// 	result = ft_strdup(s);
// 	printf("s: %s\nresult: %s\n", s, result);
// 	free(result);
// }