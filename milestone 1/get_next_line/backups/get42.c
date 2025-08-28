/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get42.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:46:49 by otlacerd          #+#    #+#             */
/*   Updated: 2025/08/28 10:37:55 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

int    liner(char **line, t_gnl *x, int *endtotal)
{
    char        *newline;
    int         index;
	int len;

	len = 0;	
    if (x->readbytes <= 0)
    	return (x->start);
    if (x->start >= x->readbytes)
		*(long *)x = 0;
    while ((x->buff[x->end] != '\n') && (x->end < x->readbytes) && ++(x->end)) // procura linha
    	(*endtotal)++;
    newline = malloc(*endtotal + 1 + (x->buff[x->end] == '\n') * sizeof(char));
    if (!newline)
    	return (x->start);
    index = -1;
	if (*line)
	{
		while ((*line)[len])
			len++;		
	}
	// printf("\n\nLEN: %d\nendtotal - end:  %d\nentotal: %d\nend: %d\n", len, *endtotal - x->end, *endtotal, x->end);
	// printf("STRING: %s\n\n", *line);
	len = 0;
    while (++index < (*endtotal - x->end)) // Copia linhas anteriores
    	newline[index] = (*line)[index];
    while ((x->start <= x->end) && (x->start < x->readbytes)) // copia nova linha
    	newline[index++] = x->buff[x->start++];
    free(*line);
    *line = newline;
	return (index);
}

char *get_next_line(int fd)
{
    static t_gnl x = {BUFFER_SIZE, 0, BUFFER_SIZE, {0}};
    char        *line;
    int         endtotal;
	int			index;

	index = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
    	return (NULL);
    if (x.readbytes == 0 || x.start >= x.readbytes)
		x = (t_gnl){BUFFER_SIZE, 0, BUFFER_SIZE, {0}};
    line = NULL;
    endtotal = 0;
    while ((x.buff[x.end] != '\n' || line == NULL) && x.readbytes > 0)
    {
        if (x.start >= x.readbytes)
        		x.readbytes = read(fd, x.buff, BUFFER_SIZE);
		if (x.readbytes == -1)
				return (x = (t_gnl){BUFFER_SIZE, 0, BUFFER_SIZE, {0}}, free(line), NULL);
        index = liner(&line, &x, &endtotal);
    }
	if (line != NULL)
		line[index] = '\0';
    return (x.end += (x.buff[x.end] == '\n'), line);
}

int main(void)
{
    int fd;
	char	*line;
    
    fd = open("./test.txt", O_RDONLY);
	while(1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		printf("Result --> %s\n", line);
		free(line);		
	}

    char *line1 = get_next_line(fd);
    printf("GET1:  %s\n", line1);
    
    char *line2 = get_next_line(fd);
    printf("GET2:  %s\n", line2);
    
    char *line3 = get_next_line(fd);
    printf("GET3:  %s\n", line3);
    
    char *line4 = get_next_line(fd);
    printf("GET4:  %s\n", line4);

    char *line5 = get_next_line(fd);
    printf("GET5:  %s\n\n", line5);

    close(fd);
	fd = open("./test.txt", O_RDONLY);
	
	line1 = get_next_line(fd);
    printf("After clone\n\nGET1:  %s\n", line1);
    
    line2 = get_next_line(fd);
    printf("GET2:  %s\n", line2);
    
    line3 = get_next_line(fd);
    printf("GET3:  %s\n", line3);
    
    line4 = get_next_line(fd);
    printf("GET4:  %s\n", line4);

    line5 = get_next_line(fd);
    printf("GET5:  %s\n\n", line5);
}