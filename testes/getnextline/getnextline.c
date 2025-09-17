/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:17:40 by otlacerd          #+#    #+#             */
/*   Updated: 2025/09/14 01:00:58 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_g	x;

	if ((fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > MAX))
		return (0);
	*((t_w *)(&x.end)) = (t_w){(x.end + ((x.buff[x.end]) == 10)), 0, 0, 0, -1};
	if (x.rbts <= 0 || x.start >= x.rbts)
		x = (t_g){{0}, 1, BUFFER_SIZE, BUFFER_SIZE, 0, 0, 0, -1};
	while ((x.line == 0 || x.buff[x.end] != 10) && x.rbts > 0)
	{
		(x.start >= x.rbts) && (x.rbts = read(fd, x.buff, BUFFER_SIZE));
		(x.start >= x.rbts) && (*(long *)&x.start = 0);
		while ((x.end < x.rbts) && (x.buff[x.end] != 10) && ++(x.end))
			++(x.totalend);
		x.nline = malloc(x.totalend + 1 + (x.buff[x.end] == 10) * sizeof(char));
		if (!x.nline)
			return (0);
		while (++(x.index) < (x.totalend - x.end) && (x.line) && x.rbts > 0)
			x.nline[x.index] = (x.line)[x.index];
		while ((x.start <= x.end) && (x.start < x.rbts) && (x.rbts > 0))
			x.nline[x.index++] = x.buff[x.start++];
		(x.nline) && (x.nline[x.index] = '\0');
		free(x.line);
		*((t_z *)(&x.line)) = (t_z){(char *)((long)x.nline * (x.rbts > 0)), -1};
	}
	return (free((void *)((long)x.nline * (x.rbts <= 0))), x.line);
}

int	main(void)
{
	int fd;
	char *line1 = "";

	fd = open("./teste1.txt", O_RDONLY);
	while (line1 != NULL)
	{
		line1 = get_next_line(0);
		if (line1 != NULL)
			printf("You wrote ->%s", line1);
		free(line1);
	}
	printf("open %i\n", fd);
	line1 = get_next_line(fd);
	printf("GET1:  %s\n", line1);
	free(line1);
	char *line2 = get_next_line(fd);
	printf("GET2:  %s\n", line2);
	free(line2);
	char *line3 = get_next_line(fd);
	printf("GET3:  %s\n", line3);
	free(line3);
	char *line4 = get_next_line(fd);
	printf("GET4:  %s\n", line4);
	free(line4);
	char *line5 = get_next_line(fd);
	printf("GET5:  %s\n\n", line5);
	free(line5);
	printf("After close:\n\n");

	close(fd);
	fd = open("./teste1.txt", O_RDONLY);
	printf("open %i\n", fd);
	line1 = get_next_line(fd);
	printf("GET1:  %s\n", line1);

	line2 = get_next_line(fd);
	printf("GET2:  %s\n", line2);

	line3 = get_next_line(fd);
	printf("GET3:  %s\n", line3);

	line4 = get_next_line(fd);
	printf("GET4:  %s\n", line4);

	line5 = get_next_line(fd);
	printf("GET5:  %s\n\n", line5);
	free(line1);
	free(line2);
	free(line3);
	free(line4);
	free(line5);
}