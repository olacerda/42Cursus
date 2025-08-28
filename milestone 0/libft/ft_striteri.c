/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:49:51 by otlacerd          #+#    #+#             */
/*   Updated: 2025/05/22 19:19:49 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	count;

	count = 0;
	if (!s || !f)
		return ;
	while (s[count] != '\0')
	{
		f(count, &s[count]);
		count++;
	}
}

/*
void	uppercaser(unsigned int a, char *b)
{
	if (*b >= 97 && *b <= 122)
		*b = *b - 32;
}

int	main(void)
{
	char	teste[] = "isso e umt este";

	printf("%s\n", teste);
	ft_striteri(teste, uppercaser);
	printf("%s\n", teste);
	
}
*/
