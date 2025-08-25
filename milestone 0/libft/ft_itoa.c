/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:41:24 by otlacerd          #+#    #+#             */
/*   Updated: 2025/05/28 00:16:50 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
*/

#include "libft.h"

static int	sizer(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		count = count + 1;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;
	int		menos;

	size = sizer(n);
	menos = 1;
	if (n < 0)
		menos = -1;
	result = (char *) malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[size] = '\0';
	while (--size >= 0)
	{
		result[size] = (n % 10) * menos + 48;
		n = n / 10;
	}
	if (menos < 0)
		result[0] = '-';
	return (result);
}

// int	main(void)
// {
// 	char	*str1 = ft_itoa(173);
// 	char	*str2 = ft_itoa(-173);
// 	char	*str3 = ft_itoa(0);
// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	printf("%s\n", str3);
// 	free(str1);
// 	free(str2);
// 	free(str3);
// }