/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:56:05 by otlacerd          #+#    #+#             */
/*   Updated: 2025/04/18 17:30:21 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = (c - 32);
	return (c);
}

/*
int	main(void)
{
	int	c;

	c = 102;
	printf("Charactere antes: %c\n", c);
	printf("Charactere depois: %c", ft_toupper(c));	
}
*/