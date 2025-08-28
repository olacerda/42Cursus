/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:46:49 by otlacerd          #+#    #+#             */
/*   Updated: 2025/06/19 03:17:29 by olacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	new(char **line, char *buffed, int *buff, int readcount, int *endcount)
{
    char        *newline;
    int         index;

    if (readcount <= 0)
    	return ;
	if (buff[START] >= readcount)
		*(long *)buff = 0;
	while (buffed[buff[END]] != '\n' && buff[END] < readcount)
		(buff[END])++, (*endcount)++;
    newline = malloc(((*endcount) + 1 + (buffed[(buff[END])] == '\n')) * sizeof(char));
    if (!newline)
		return ;
    index = -1;
    while (++index < (*endcount - buff[END]))
		newline[index] = (*line)[index];
    while (buff[START] <= (buff[END]))
		newline[index++] = buffed[(buff[START])++];
    newline[index] = '\0';
    free(*line);
	*line = newline;
}

char *get_next_line(int fd)
{
    static char buffed[BUFFER_SIZE];
    static int  readcount = BUFFER_SIZE;
    static int	buff[] = {BUFFER_SIZE, 0};
    char 		*line;
    int         endcount;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (readcount == 0)
	{
		readcount = BUFFER_SIZE;
		buff[START] = BUFFER_SIZE;
		buff[END] = 0;
	}
	line = NULL;
	endcount = 0;
    while ((buffed[buff[END]] != '\n' && readcount > 0) || \
		((line == NULL || line[endcount] != '\n') && readcount > 0))
    {
        if (buff[START] >= readcount)
        		readcount = read(fd, buffed, BUFFER_SIZE);
		new(&line, buffed, buff, readcount, &endcount);
    }
	buff[END] += (buffed[buff[END]] == '\n');
    return (line);
}

int main(void)
{
    int fd;

    fd = open("./test.txt", O_RDONLY);
	printf("open %i\n", fd);
    char *line1 = get_next_line(fd);
    printf("GET1:  %s\n\n\n", line1);
    
    char *line2 = get_next_line(fd);
    printf("GET2:  %s\n\n\n", line2);
    
    char *line3 = get_next_line(fd);
    printf("GET3:  %s\n\n\n", line3);
	
    char *line4 = get_next_line(fd);
    printf("GET4:  %s\n\n\n", line4);
	
    char *line5 = get_next_line(fd);
    printf("GET5:  %s\n\n\n", line5);

	printf("After close:\n\n\n");
	
	close(fd);
    fd = open("./test.txt", O_RDONLY);
	printf("open %i\n", fd);
    line1 = get_next_line(fd);
    printf("GET1:  %s\n\n", line1);
    
    line2 = get_next_line(fd);
    printf("GET2:  %s\n\n\n", line2);
    
    line3 = get_next_line(fd);
    printf("GET3:  %s\n\n\n", line3);
	
    line4 = get_next_line(fd);
    printf("GET4:  %s\n\n\n", line4);
	
    line5 = get_next_line(fd);
    printf("GET5:  %s\n\n\n", line5);
}