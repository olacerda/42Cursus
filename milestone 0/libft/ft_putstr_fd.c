/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:52:57 by otlacerd          #+#    #+#             */
/*   Updated: 2025/05/22 19:29:54 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
		return ;
	while (s[count] != '\0')
		count++;
	write(fd, s, count);
}

/*
int	main(void)
{
	char	teste[] = "isso e um teste";
	int	fd;

	fd = open("!!! PASTE_THE_FILE'S", O_WRONLY);
	ft_putstr_fd(teste, fd);
}
*/