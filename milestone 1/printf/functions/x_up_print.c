/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_up_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:03:55 by otlacerd          #+#    #+#             */
/*   Updated: 2025/06/05 17:13:50 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	hexxor(uintptr_t number, char *base)
{
	int		count;
	char	print;

	count = 0;
	if (number >= 16)
		count = hexxor(number / 16, base);
	print = (base[number % 16]);
	return (count + write(1, &print, 1));
}

int	x_up_print(const char **argument, va_list args)
{
	unsigned int	x_up;
	char			*base;
	uintptr_t		number;

	if (**argument == '%' && *((*argument) + 1) == 'X')
	{
		x_up = va_arg(args, unsigned int);
		*argument = *argument + 2;
		base = "0123456789ABCDEF";
		number = (uintptr_t)x_up;
		return (hexxor(number, base));
	}
	return (0);
}

// static int	valister(const char **str, ...)
// {
// 	va_list	args;
// 	int	result;

// 	va_start(args, str);
// 	result = x_up_print(str, args);
// 	va_end(args);
// 	return (result);
// }

// int	main(void)
// {
// 	const char	*str = "%X";
// 	int		X;
// 	int		result;

// 	X = 200;
// 	result = valister(&str, X);
// 	printf("  <-- (Writen Count: %d)\n\n", result);
// 	printf("%X  <-- (Original Prinft)\n", X);
// }