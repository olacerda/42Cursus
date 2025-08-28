/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:12:04 by otlacerd          #+#    #+#             */
/*   Updated: 2025/05/20 22:18:53 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		count;
	long	resulttemp;
	int		result;

	count = 0;
	resulttemp = 0;
	result = 1;
	while ((nptr[count] >= 9 && nptr[count] <= 13) || nptr[count] == 32)
		count++;
	if (nptr[count] == '+' || nptr[count] == '-')
	{
		if (nptr[count] == '-')
			result = -result;
		count++;
	}
	while (nptr[count] >= '0' && nptr[count] <= '9')
	{
		resulttemp = resulttemp * 10 + (nptr[count] - 48);
		count++;
	}
	resulttemp = resulttemp * result;
	if (resulttemp > 2147483647 || resulttemp < -2147483648)
		return (0);
	result = resulttemp;
	return (result);
}

/*
int	main(void)
{
	const char	nptr[] = "      +2147483647abc564";

	printf("%d", ft_atoi(nptr));
}
*/