/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:36:55 by otlacerd          #+#    #+#             */
/*   Updated: 2025/05/20 23:29:42 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	number;
	char		result;

	number = n;
	if (number < 0)
	{
		write(fd, "-", 1);
		number = -number;
	}
	if (number >= 10)
		ft_putnbr_fd(number / 10, fd);
	result = number % 10 + 48;
	write (fd, &result, 1);
}

/*
int	main(void)
{
	int	number;
	int	fd;

	number = 173;
	fd = open("!!!! PASTE_THE_FULL_ADRESS_HERE !!!!", O_WRONLY);
	ft_putnbr_fd(number, fd);
}
*/