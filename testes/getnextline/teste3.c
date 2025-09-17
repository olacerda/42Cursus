/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:48:09 by olacerda          #+#    #+#             */
/*   Updated: 2025/09/09 11:33:41 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>

void	teste(void)
{
	struct teste {int a, b;} x = {10, 10};
	int	a = 2;
	int	b = 7;

	printf("a: %d\nb: %d\n\n", x.a, x.b);
	*(long *)&x = 0;
	printf("a: %d\nb: %d\n\n", x.a, x.b);

	*(long *)&x = (((long)b << 32) + a);
	printf("a: %d\nb: %d\n\n", x.a, x.b);
}

int	main(void)
{
	teste();
}