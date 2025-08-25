/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:16:38 by otlacerd          #+#    #+#             */
/*   Updated: 2025/05/22 19:17:46 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* 
int	main(void)
{
	char	c;
	int	fd;

	c = 'Z';
	fd = open("!!!! PASTE_THE_FULL_ADRESS_HERE !!!!", O_WRONLY);
	if (fd < 0)
		return (0);
	ft_putchar_fd(c, fd);
}
 */