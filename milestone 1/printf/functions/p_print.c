/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:04:02 by otlacerd          #+#    #+#             */
/*   Updated: 2025/06/05 18:59:53 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	hexxor(uintptr_t number, char *base)
{
	char	print;
	int		count;

	count = 0;
	if (number >= 16)
		count = hexxor(number / 16, base);
	print = (base[number % 16]);
	return (count + write(1, &print, 1));
}

int	p_print(const char **argument
, va_list args)
{
	char		*base;
	uintptr_t	number;
	int			count;
	void		*p;

	count = 0;
	if (**argument == '%' && *((*argument) + 1) == 'p')
	{
		p = va_arg(args, void *);
		*argument = *argument + 2;
		if (!p)
			return (write(1, "(nil)", 5));
		base = "0123456789abcdef";
		number = (uintptr_t)p;
		count = write(1, "0x", 2);
		count = count + hexxor(number, base);
		return (count);
	}
	return (0);
}

// static int	valister(const char **str, ...)
// {
// 	va_list	args;
// 	int	result;

// 	va_start(args, str);
// 	result = p_print(str, args);
// 	va_end(args);
// 	return (result);
// }

// int	main(void)
// {
// 	const char	*str = "%p";
// 	void	*p;
// 	int		result;
// 	int		test;

// 	test = 777;
// 	p = &test;
// 	result = valister(&str, p);
// 	printf("   (Writen Count: %d)\n", result);
// 	printf("\n%p  <-- Original printf\n\n", p); // <--- Printf ORIGINAL
// }