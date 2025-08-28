/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:58:00 by otlacerd          #+#    #+#             */
/*   Updated: 2025/05/21 23:59:24 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*result;
	size_t			count;

	count = 0;
	if (nmemb != 0 && size > ((size_t)-1) / nmemb)
		return (NULL);
	if ((nmemb * size) == 0)
		result = (unsigned char *) malloc(1);
	else
		result = (unsigned char *) malloc(nmemb * size);
	if (!result)
		return (NULL);
	while (count < (nmemb * size))
	{
		result[count] = '\0';
		count++;
	}
	return ((void *)result);
}

// int	main(void)
// {
// 	char	*teste = "teste";
// 	size_t	nmemb;
// 	size_t	size;
// 	size_t	count;

// 	count = 0;
// 	nmemb = 5;
// 	size = 1;
// 	printf("Primeira string: ");
// 	while (count < nmemb)
// 	{
// 		if (teste[count] == '\0')
// 			printf("NULL ");
// 		printf("%c", teste[count]);
// 		count++;
// 	}
// 	teste = (char *) ft_calloc(nmemb, size);
// 	count = 0;
// 	printf("\nSegunda string: ");
// 	while (count < nmemb)
// 	{
// 		if (teste[count] == '\0')
// 			printf("NULL ");
// 		else
// 			printf("%c", teste[count]);
// 		count++;
// 	}
// 	free(teste);
// }
