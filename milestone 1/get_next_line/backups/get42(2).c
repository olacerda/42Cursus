/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:37:25 by otlacerd          #+#    #+#             */
/*   Updated: 2025/08/27 10:57:47 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "temp.h"

char	*get_next_line(int fd)
{
	static t_g	x[FD_SETSIZE];

	if ((x[fd].nln = NULL) && (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > MAX))
		return (NULL);
	if (!(x[fd].ln = NULL) && (x[fd].byt <= 0 || x[fd].sta >= x[fd].byt))
		x[fd] = (t_g){1, 0, 0, 1, NULL, {0}, &x[fd].buf[0], &x[fd].tmp, 0, NULL};
	while ((x[fd].ln == NULL || x[fd].buf[0][x[fd].end] != 10) && x[fd].byt > 0)
	{
		if (x[fd].sta >= x[fd].byt)
		{
			x[fd].byt = read(fd, x[fd].buf[0], BUFFER_SIZE);
			(*(long *)&(x[fd]) = 0);
		}
		while ((x[fd].buf[0][x[fd].end] != 10) && (x[fd].end < x[fd].byt) && ++(x[fd].end))
			(x[fd].tot)++;
		x[fd].nln = malloc(x[fd].tot + 1 + (x[fd].buf[0][x[fd].end] == 10) * sizeof(char));
		if ((x[fd].idx = -1) && (!x[fd].nln))
			return (NULL);
		while (++x[fd].idx < (x[fd].tot - x[fd].end) && x[fd].ln && x[fd].byt > 0)
			x[fd].nln[x[fd].idx] = (x[fd].ln)[x[fd].idx];
		while ((x[fd].sta <= x[fd].end) && (x[fd].sta < x[fd].byt) && x[fd].byt > 0)
			x[fd].nln[x[fd].idx++] = x[fd].buf[0][x[fd].sta++];
		free(x[fd].ln);
		((x[fd].byt > 0) && (x[fd].ln = x[fd].nln));
	}
	return (((x[fd].ln != NULL) && (x[fd].nln[x[fd].idx] = 0)), x[fd].end += 
	(x[fd].buf[0][x[fd].end]) == 10, x[fd].tot = 0, x[fd].ln);
}

int main(void)
{
    char    *line;

    while (1)
    {
        line = get_next_line(0);
        if (!line)
            break ;
		printf("You wrote: %s", line);
        free(line);
    }
	int fd1;
	int	fd2;
	int	fd3;

    fd1 = open("./teste1.txt", O_RDONLY);
	fd2 = open("./teste2.txt", O_RDONLY);
	fd3 = open("./teste3.txt", O_RDONLY);

	char *line1 = get_next_line(fd1);
    printf("GET1:  %s\n", line1);
	free(line1);
    char *line2 = get_next_line(fd2);
    printf("GET2:  %s\n", line2);
	free(line2);
    char *line3 = get_next_line(fd3);
    printf("GET3:  %s\n", line3);
	free(line3);
	line1 = get_next_line(fd1);
    printf("GET1:  %s\n", line1);
	free(line1);
    line2 = get_next_line(fd2);
    printf("GET2:  %s\n", line2);
	free(line2);
    line3 = get_next_line(fd3);
    printf("GET3:  %s\n", line3);
	free(line3);
	line1 = get_next_line(fd1);
    printf("GET1:  %s\n", line1);
	free(line1);
    line2 = get_next_line(fd2);
    printf("GET2:  %s\n", line2);
	free(line2);
    line3 = get_next_line(fd3);
    printf("GET3:  %s\n", line3);
	free(line3);
	line1 = get_next_line(fd1);
    printf("GET1:  %s\n", line1);
	free(line1);
    line2 = get_next_line(fd2);
    printf("GET2:  %s\n", line2);
	free(line2);
    line3 = get_next_line(fd3);
    printf("GET3:  %s\n", line3);
	free(line3);
	line1 = get_next_line(fd1);
    printf("GET1:  %s\n", line1);
	free(line1);
    line2 = get_next_line(fd2);
    printf("GET2:  %s\n", line2);
	free(line2);
    line3 = get_next_line(fd3);
    printf("GET3:  %s\n", line3);
	free(line3);

    close(fd1);
    close(fd2);
    close(fd3);
	printf("\n\nAfter close\n\n");

    fd1 = open("./teste1.txt", O_RDONLY);
	fd2 = open("./teste2.txt", O_RDONLY);
	fd3 = open("./teste3.txt", O_RDONLY);

	line1 = get_next_line(fd1);
    printf("GET1:  %s\n", line1);
	free(line1);
    line2 = get_next_line(fd2);
    printf("GET2:  %s\n", line2);
	free(line2);
    line3 = get_next_line(fd3);
    printf("GET3:  %s\n", line3);
	free(line3);
	line1 = get_next_line(fd1);
    printf("GET1:  %s\n", line1);
	free(line1);
    line2 = get_next_line(fd2);
    printf("GET2:  %s\n", line2);
	free(line2);
    line3 = get_next_line(fd3);
    printf("GET3:  %s\n", line3);
	free(line3);
	line1 = get_next_line(fd1);
    printf("GET1:  %s\n", line1);
	free(line1);
    line2 = get_next_line(fd2);
    printf("GET2:  %s\n", line2);
	free(line2);
    line3 = get_next_line(fd3);
    printf("GET3:  %s\n", line3);
	free(line3);
	line1 = get_next_line(fd1);
    printf("GET1:  %s\n", line1);
	free(line1);
    line2 = get_next_line(fd2);
    printf("GET2:  %s\n", line2);
	free(line2);
    line3 = get_next_line(fd3);
    printf("GET3:  %s\n", line3);
	free(line3);
	line1 = get_next_line(fd1);
    printf("GET1:  %s\n", line1);
	free(line1);
    line2 = get_next_line(fd2);
    printf("GET2:  %s\n", line2);
	free(line2);
    line3 = get_next_line(fd3);
    printf("GET3:  %s\n", line3);
	free(line3);
	close(fd1);
	close(fd2);
	close(fd3);
}