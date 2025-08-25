/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:08:54 by otlacerd          #+#    #+#             */
/*   Updated: 2025/06/05 19:00:17 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *argument, ...);

int	perc_print(const char **argument);
int	c_print(const char **argument, va_list args);
int	d_print(const char **argument, va_list args);
int	i_print(const char **argument, va_list args);
int	p_print(const char **argument, va_list args);
int	s_print(const char **argument, va_list args);
int	u_print(const char **argument, va_list args);
int	x_print(const char **argument, va_list args);
int	x_up_print(const char **argument, va_list args);

#endif