/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:03:59 by otlacerd          #+#    #+#             */
/*   Updated: 2025/06/05 17:51:24 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	u_printer(unsigned int u)
{
	char			result;
	int				count;

	count = 0;
	if (u >= 10)
		count = u_printer(u / 10);
	result = u % 10 + 48;
	return (count + write(1, &result, 1));
}

int	u_print(const char **argument, va_list args)
{
	unsigned int	u;

	if (**argument == '%' && *((*argument) + 1) == 'u')
	{
		u = va_arg(args, unsigned int);
		*argument = *argument + 2;
		return (u_printer(u));
	}
	return (0);
}

// static int	valister(const char **str, ...)
// {
// 	va_list	args;
// 	int	result;

// 	va_start(args, str);
// 	result = u_print(str, args);
// 	va_end(args);
// 	return (result);
// }

// int	main(void)
// {
// 	const char			*str = "%u";
// 	unsigned int	u;
// 	int		result;

// 	u = 71;
// 	result = valister(&str, u);
// 	printf("  <-- (Writen Count: %d)\n", result);
// 	printf("\n%u  <-- (Original printf)\n\n", u); // <--- Printf ORIGINAL
// }