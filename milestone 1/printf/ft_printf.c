/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:29:14 by otlacerd          #+#    #+#             */
/*   Updated: 2025/08/10 18:03:55 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *argument, ...)
{
	va_list	args;
	int		count;

	va_start(args, argument);
	if (!argument)
		return (-1);
	count = 0;
	while (*argument)
	{
		if (*argument == '%')
		{
			count += c_print(&argument, args);
			count += s_print(&argument, args);
			count += i_print(&argument, args);
			count += d_print(&argument, args);
			count += u_print(&argument, args);
			count += p_print(&argument, args);
			count += x_print(&argument, args);
			count += x_up_print(&argument, args);
			count += perc_print(&argument);
		}
		else if (*argument)
			count += write(1, argument++, 1);
	}
	return (va_end(args), count);
}

// int	main(void)
// {
// 	int				d;
// 	int				i;
// 	char			c;
// 	char			*p = "Teste p";
// 	char			*s = "Teste s";
// 	unsigned int	u;
// 	unsigned int	x;
// 	unsigned int	x_up;
// 	char			perc;

// 	d = 7777777;
// 	i = 17;
// 	c = 'Z';
// 	u = 71;
// 	x = 200;
// 	x_up = 300;
// 	perc = '%';
// 	ft_printf("Variables type:\nd: %d\ni: %i\nc: %c\np: %p\ns: %s\nu: %u\nx: \
// 		%x\nX: %X\nperentage: %%\n", d, i, c, p, s, u, x, x_up, perc);
// }