/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:04:03 by otlacerd          #+#    #+#             */
/*   Updated: 2025/06/05 18:21:55 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	i_printer(int i)
{
	long int	number;
	char		result;
	int			count;

	number = i;
	count = 0;
	if (number < 0)
	{
		count += write(1, "-", 1);
		number = -number;
	}
	if (number >= 10)
		count = count + i_printer(number / 10);
	result = number % 10 + 48;
	return (count + write(1, &result, 1));
}

int	i_print(const char **argument, va_list args)
{
	int	i;

	if (**argument == '%' && *((*argument) + 1) == 'i')
	{
		i = va_arg(args, int);
		*argument = *argument + 2;
		return (i_printer(i));
	}
	return (0);
}

// static int	valister(const char **str, ...)
// {
// 	va_list	args;
// 	int	result;

// 	va_start(args, str);
// 	result = i_print(str, args);
// 	va_end(args);
// 	return (result);
// }

// int	main(void)
// {
// 	const char	*str = "%i";
// 	int		i;
// 	int		result;

// 	i = 177;
// 	result = valister(&str, i);
// 	printf("  <-- (Writen Count: %d)\n\n", result);
// 	printf("%i  <-- (Original Prinft)\n", i);
// }