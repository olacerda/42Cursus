/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 07:59:28 by olacerda          #+#    #+#             */
/*   Updated: 2025/09/09 10:43:02 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>

// void	teste(void)
// {
// 	struct s_teste {int a, b; char *c, *d; int e;} *x = &(struct s_teste){0, 0, 0, 0, 0};
// 	int z = 3;
// 	printf("a: %d\nb: %d\nc: %s\nd: %s\ne: %d", x->a, x->b, x->c, x->d, x->e);

// 	*x = (struct s_teste){1, 2, "teste", "oi", 3};
// 	printf("\n\na: %d\nb: %d\nc: %s\nd: %s\ne: %d\n\n", x->a, x->b, x->c, x->d, x->e);

// 	(void)((z > 2) && (x = &(struct s_teste){99, 41, "puta que pariu", "não acredito", 7}));
// 	printf("\n\na: %d\nb: %d\nc: %s\nd: %s\ne: %d\n\n", x->a, x->b, x->c, x->d, x->e);

// 	(void)((z > 2) && ((struct s_outra {int a, b;} *)x = (struct s_outra *)&{99, 41}));
// 	printf("\n\na: %d\nb: %d\nc: %s\nd: %s\ne: %d\n\n", x->a, x->b, x->c, x->d, x->e);
// }

// void	teste(void)
// {
// 	struct s_teste {int a, b; char *c, *d; int e;}x = (struct s_teste){0, 0, 0, 0, 0};
// 	int z = 3;
// 	printf("a: %d\nb: %d\nc: %s\nd: %s\ne: %d", x.a, x.b, x.c, x.d, x.e);

// 	x = (struct s_teste){1, 2, "teste", "oi", 3};
// 	printf("\n\na: %d\nb: %d\nc: %s\nd: %s\ne: %d\n\n", x.a, x.b, x.c, x.d, x.e);

// 	(void)((z > 2) && (x = &(struct s_teste){99, 41, "puta que pariu", "não acredito", 7}));
// 	printf("\n\na: %d\nb: %d\nc: %s\nd: %s\ne: %d\n\n", x.a, x.b, x.c, x.d, x.e);

// 	(void)((z > 2) && (*((struct s_outra {int a, b;})*)&x) = (struct s_outra)&{99, 41}));
// 	printf("\n\na: %d\nb: %d\nc: %s\nd: %s\ne: %d\n\n", x.a, x.b, x.c, x.d, x.e);
// }

void	teste(void)
{
	struct s_teste {int a; char b;} x = (struct s_teste){'z', 0};

	

	printf("%li\n\n %d\n", sizeof(struct s_teste), x.a);
}

int	main(void)
{
	teste();
}
