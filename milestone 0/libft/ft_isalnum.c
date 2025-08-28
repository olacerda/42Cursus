/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:54:07 by otlacerd          #+#    #+#             */
/*   Updated: 2025/04/18 17:29:04 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) \
		|| (c >= 65 && c <= 90) \
		|| (c >= 97 && c <= 122))
		return (1);
	return (0);
}

/*
int	main(void)
{
	int	teste;
	int	c;

	c = 123;
	teste = ft_isalnum(c);
	printf("%d", teste);
}
*/