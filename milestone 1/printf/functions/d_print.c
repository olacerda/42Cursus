/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:04:04 by otlacerd          #+#    #+#             */
/*   Updated: 2025/06/05 17:48:40 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	d_printer(int d)
{
	long int	number;
	char		result;
	int			count;

	count = 0;
	number = d;
	if (number < 0)
	{
		count = count + write(1, "-", 1);
		number = -number;
	}
	if (number >= 10)
		count = count + d_printer(number / 10);
	result = number % 10 + 48;
	return (count + write(1, &result, 1));
}

int	d_print(const char **argument, va_list args)
{
	int	d;

	if (**argument == '%' && *((*argument) + 1) == 'd')
	{
		d = va_arg(args, int);
		*argument = *argument + 2;
		return (d_printer(d));
	}
	return (0);
}

// static int	valister(const char **str, ...)
// {
// 	va_list	args;
// 	int	result;

// 	va_start(args, str);
// 	result = d_print(str, args);
// 	va_end(args);
// 	return (result);
// }

// int	main(void)
// {
// 	const char	*str = "%d";
// 	int		d;
// 	int		result;

// 	d = 17;
// 	result = valister(&str, d);
// 	printf("  <-- (Writen Count: %d)\n\n", result);
// 	printf("%d  <-- (Original Prinft)\n", d);
// }