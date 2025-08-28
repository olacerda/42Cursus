/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:01:55 by otlacerd          #+#    #+#             */
/*   Updated: 2025/06/08 21:36:20 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
		return ;
	while (s[count])
		count++;
	write(fd, s, count);
	write(fd, "\n", 1);
}

/*
int	main(void)
{
	char	s[] = "isso e um teste";
	int	fd;

	fd = open("!!! Paste the Adress", O_WRONLY);
	ft_putendl_fd(s, fd);
}
*/