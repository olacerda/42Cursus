/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:04:05 by otlacerd          #+#    #+#             */
/*   Updated: 2025/06/05 17:20:30 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	c_print(const char **argument, va_list args)
{
	int	c;

	c = 0;
	if (**argument == '%' && *((*argument) + 1) == 'c')
	{
		c = va_arg(args, int);
		*argument = *argument + 2;
		return (write(1, &c, 1));
	}
	return (0);
}

// static int	valister(const char **str, ...)
// {
// 	va_list	args;
// 	int	result;

// 	va_start(args, str);
// 	result = c_print(str, args);
// 	va_end(args);
// 	return (result);
// }

// int	main(void)
// {
// 	const char	*str = "%c";
// 	int		c;
// 	int		result;

// 	c = 90;
// 	result = valister(&str, c);
// 	printf("  <-- (Writen Count: %d)\n\n", result);
// 	printf("%c  <-- Original Priintf\n", c);
// }
