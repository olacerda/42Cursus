/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:04:07 by otlacerd          #+#    #+#             */
/*   Updated: 2025/06/05 17:13:50 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	perc_print(const char **argument
)
{
	if (**argument == '%' && *((*argument) + 1) == '%')
	{
		*argument = *argument + 2;
		return (write(1, "%", 1));
	}
	return (0);
}

// static int	valister(const char **str)
// {
// 	int	result;

// 	result = perc_print(str);
// 	return (result);
// }

// int	main(void)
// {
// 	const char	*str = "%%";
// 	int		result;

// 	result = valister(&str);
// 	printf("  <-- (Writen Count: %d)\n", result);
// 	printf("\n%%  <-- (Original printf)\n\n"); // <--- Printf ORIGINAL
// }