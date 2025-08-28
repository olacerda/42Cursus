/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:46:49 by otlacerd          #+#    #+#             */
/*   Updated: 2025/06/16 19:46:16 by olacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *newline(char **lastline, char *buffed, int *start, int end, int readded, int endtotal)
{
    char 		*line;
    int 		index;

	if (readded <= 0 && *start == readded)
		return (NULL);
	index = 0;
	if (*start >= readded)
		*start = 0;
    line = malloc((endtotal + 2) * sizeof(char));
    if (!line)
        return (NULL);
    while (index < (endtotal - end))
	{
        line[index] = (*lastline)[index];
		index++;
	}
    while (*start < end && (readded - *start))
		line[index++] = buffed[(*start)++];
	line[index++] = '\n';
    line[index] = '\0';
	free(*lastline);
    return (line);
}

char *get_next_line(int fd)
{
    static char	buffed[BUFFER_SIZE];
    static char *line = NULL;
	int 		endtotal = 0;
    static int 	end = 0;
	static int	start = BUFFER_SIZE;
    static int 	readded = BUFFER_SIZE;

    if (fd < 0)
    	return (NULL);
    while (buffed[end] != '\n' && readded > 0)
    {
        if (start >= readded)
        {
            end = 0;
            readded = read(fd, buffed, BUFFER_SIZE);
        }
        while (buffed[end] != '\n' && end < readded)
		{
			end++;
			endtotal++;
		}
        line = newline(&line, buffed, &start, end, readded, endtotal);
    }
	if (buffed[end++] == '\n')
		start++;
    return (line);
}


int main(void)
{
    int fd;

    fd = open("/home/olacerda/projetos/get_next_line/test.txt", O_RDONLY);
    char *line1 = get_next_line(fd);
    printf("GET1:  %s\n", line1);
    
    char *line2 = get_next_line(fd);
    printf("GET2:  %s\n", line2);
    
    char *line3 = get_next_line(fd);
    printf("GET3:  %s\n", line3);
    
    char *line4 = get_next_line(fd);
    printf("GET4:  %s\n", line4);

	char *line5 = get_next_line(fd);
    printf("GET5:  %s\n", line5);
}
