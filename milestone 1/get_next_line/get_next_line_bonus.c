/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:37:25 by otlacerd          #+#    #+#             */
/*   Updated: 2025/08/27 10:40:39 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line_bonus.h"

char	*get_next_line_bonus(int fd)
{
	static t_g	x[FD_SETSIZE];
	char		*ln;
	int			endtotal;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > MAX_BUFFERSIZE)
		return (NULL);
	if (x[fd].readbytes <= 0 || x[fd].start >= x[fd].readbytes)
		x[fd] = (t_g){BUFFER_SIZE, 0, BUFFER_SIZE, {0}};
	ln = NULL;
	endtotal = 0;
	while ((x[fd].buff[x[fd].end] != '\n' || ln == NULL) && x[fd].readbytes > 0)
	{
		if (x[fd].start >= x[fd].readbytes)
			x[fd].readbytes = read(fd, x[fd].buff, BUFFER_SIZE);
		ln = liner(&ln, &x[fd], &endtotal);
	}
	return (x[fd].end += (x[fd].buff[x[fd].end] == '\n'), ln);
}

int main(void)
{
    char    *line;

    while (1)
    {
        line = get_next_line_bonus(0);
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

	char *line1 = get_next_line_bonus(fd1);
    printf("GET1:  %s\n", line1);
	free(line1);
    char *line2 = get_next_line_bonus(fd2);
    printf("GET2:  %s\n", line2);
	free(line2);
    char *line3 = get_next_line_bonus(fd3);
    printf("GET3:  %s\n", line3);
	free(line3);
	line1 = get_next_line_bonus(fd1);
    printf("GET1:  %s\n", line1);
	free(line1);
    line2 = get_next_line_bonus(fd2);
    printf("GET2:  %s\n", line2);
	free(line2);
    line3 = get_next_line_bonus(fd3);
    printf("GET3:  %s\n", line3);
	free(line3);
	line1 = get_next_line_bonus(fd1);
    printf("GET1:  %s\n", line1);
	free(line1);
    line2 = get_next_line_bonus(fd2);
    printf("GET2:  %s\n", line2);
	free(line2);
    line3 = get_next_line_bonus(fd3);
    printf("GET3:  %s\n", line3);
	free(line3);
	line1 = get_next_line_bonus(fd1);
    printf("GET1:  %s\n", line1);
	free(line1);
    line2 = get_next_line_bonus(fd2);
    printf("GET2:  %s\n", line2);
	free(line2);
    line3 = get_next_line_bonus(fd3);
    printf("GET3:  %s\n", line3);
	free(line3);
	line1 = get_next_line_bonus(fd1);
    printf("GET1:  %s\n", line1);
	free(line1);
    line2 = get_next_line_bonus(fd2);
    printf("GET2:  %s\n", line2);
	free(line2);
    line3 = get_next_line_bonus(fd3);
    printf("GET3:  %s\n", line3);
	free(line3);

    close(fd1);
    close(fd2);
    close(fd3);
	printf("\n\nAfter close\n\n");

    fd1 = open("./teste1.txt", O_RDONLY);
	fd2 = open("./teste2.txt", O_RDONLY);
	fd3 = open("./teste3.txt", O_RDONLY);

	line1 = get_next_line_bonus(fd1);
    printf("GET1:  %s\n", line1);
	free(line1);
    line2 = get_next_line_bonus(fd2);
    printf("GET2:  %s\n", line2);
	free(line2);
    line3 = get_next_line_bonus(fd3);
    printf("GET3:  %s\n", line3);
	free(line3);
	line1 = get_next_line_bonus(fd1);
    printf("GET1:  %s\n", line1);
	free(line1);
    line2 = get_next_line_bonus(fd2);
    printf("GET2:  %s\n", line2);
	free(line2);
    line3 = get_next_line_bonus(fd3);
    printf("GET3:  %s\n", line3);
	free(line3);
	line1 = get_next_line_bonus(fd1);
    printf("GET1:  %s\n", line1);
	free(line1);
    line2 = get_next_line_bonus(fd2);
    printf("GET2:  %s\n", line2);
	free(line2);
    line3 = get_next_line_bonus(fd3);
    printf("GET3:  %s\n", line3);
	free(line3);
	line1 = get_next_line_bonus(fd1);
    printf("GET1:  %s\n", line1);
	free(line1);
    line2 = get_next_line_bonus(fd2);
    printf("GET2:  %s\n", line2);
	free(line2);
    line3 = get_next_line_bonus(fd3);
    printf("GET3:  %s\n", line3);
	free(line3);
	line1 = get_next_line_bonus(fd1);
    printf("GET1:  %s\n", line1);
	free(line1);
    line2 = get_next_line_bonus(fd2);
    printf("GET2:  %s\n", line2);
	free(line2);
    line3 = get_next_line_bonus(fd3);
    printf("GET3:  %s\n", line3);
	free(line3);
	close(fd1);
	close(fd2);
	close(fd3);
}