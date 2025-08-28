/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:04:01 by otlacerd          #+#    #+#             */
/*   Updated: 2025/06/05 17:46:29 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	s_print(const char **argument, va_list args)
{
	char	*s;
	int		count;

	count = 0;
	if (**argument == '%' && *((*argument) + 1) == 's')
	{
		s = va_arg(args, char *);
		*argument = *argument + 2;
		if (!s)
			return (write(1, "(null)", 6));
		while (*s)
		{
			count = count + write(1, s, 1);
			s++;
		}
		return (count);
	}
	return (0);
}

// static int	valister(const char **str, ...)
// {
// 	va_list	args;
// 	int	result;

// 	va_start(args, str);
// 	result = s_print(str, args);
// 	va_end(args);
// 	return (result);
// }

// int	main(void)
// {
// 	const char	*str = "%s";
// 	char	*s = "Ola";
// 	int		result;

// 	result = valister(&str, s);
// 	printf("  <-- (Writen Count: %d)\n", result);
// 	printf("\n%s  <-- (Original printf)\n\n", s); // <--- Printf ORIGINAL
// }