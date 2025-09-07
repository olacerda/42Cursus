/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:46:49 by otlacerd          #+#    #+#             */
/*   Updated: 2025/08/15 05:08:37 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	static int	x[] = {BUFFER_SIZE, 0, BUFFER_SIZE};
	char		*line;
	int			endall;

	if (fd < 0 || BUFFER_SIZE <= 0 || x[READBYTES] < 0)
		return (NULL);
	if (x[READBYTES] <= 0 || x[START] >= x[READBYTES])
	{
		x[START] = BUFFER_SIZE;
		x[END] = 0;
		x[READBYTES] = BUFFER_SIZE;
	}
	line = NULL;
	endall = 0;
	while ((buff[x[END]] != '\n' || line == NULL) && x[READBYTES] > 0)
	{
		if (x[START] >= x[READBYTES])
			x[READBYTES] = read(fd, buff, BUFFER_SIZE);
		if (x[READBYTES] == -1)
			return (x[READBYTES] = 0, x[START] = BUFFER_SIZE, x[END] = 0,
				free(line), NULL);
		new(&line, buff, x, &endall);
	}
	return (x[END] += (buff[x[END]] == '\n'), line);
}

void	new(char **line, char *buff, int *x, int *endall)
{
	char	*newline;
	int		index;

	if (x[READBYTES] <= 0)
		return ;
	if (x[START] >= x[READBYTES])
		*(long *)x = 0;
	while (buff[x[END]] != '\n' && x[END] < x[READBYTES] && ++(x[END]))
		(*endall)++;
	newline = malloc(((*endall) + 1 + (buff[(x[END])] == '\n')) * sizeof(char));
	if (!newline)
		return ;
	index = -1;
	while (++index < (*endall - x[END]))
		newline[index] = (*line)[index];
	while (x[START] <= (x[END]) && x[START] < x[READBYTES])
		newline[index++] = buff[(x[START])++];
	newline[index] = '\0';
	free(*line);
	*line = newline;
}


int	main(void)
{
	write(3, "teste", 5);

	// fd = open("./teste1.txt", O_RDONLY);
	// printf("open %i\n", fd);
	// char *line1 = get_next_line(fd);
	// printf("GET1:  %s\n", line1);
	// free(line1);
	// char *line2 = get_next_line(fd);
	// printf("GET2:  %s\n", line2);
	// free(line2);
	// char *line3 = get_next_line(fd);
	// printf("GET3:  %s\n", line3);
	// free(line3);
	// char *line4 = get_next_line(fd);
	// printf("GET4:  %s\n", line4);
	// free(line4);
	// char *line5 = get_next_line(fd);
	// printf("GET5:  %s\n\n", line5);
	// free(line5);
	// printf("After close:\n\n");

	// close(fd);
	// fd = open("./teste1.txt", O_RDONLY);
	// printf("open %i\n", fd);
	// line1 = get_next_line(fd);
	// printf("GET1:  %s\n", line1);

	// line2 = get_next_line(fd);
	// printf("GET2:  %s\n", line2);

	// line3 = get_next_line(fd);
	// printf("GET3:  %s\n", line3);

	// line4 = get_next_line(fd);
	// printf("GET4:  %s\n", line4);

	// line5 = get_next_line(fd);
	// printf("GET5:  %s\n\n", line5);
	// free(line1);
	// free(line2);
	// free(line3);
	// free(line4);
	// free(line5);
}