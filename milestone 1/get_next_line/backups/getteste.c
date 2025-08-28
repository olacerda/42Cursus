/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getteste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:46:49 by otlacerd          #+#    #+#             */
/*   Updated: 2025/06/11 11:14:18 by olacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *nextline(char **currentLINE, char *buffada, int *bufferSTART, int bufferEND, int readded, int ENDTOTAL)
{
    char 		*line;
    int 		index;

	index = 0;
	if (readded <= 0)
		return (NULL);
	if ((readded - *bufferSTART) <= 0)
		*bufferSTART = 0;
    line = malloc((ENDTOTAL + 2) * sizeof(char));
    if (!line)
        return (NULL);
    while (index < (ENDTOTAL - bufferEND) && readded > 0)
	{
        line[index] = (*currentLINE)[index];
		index++;
	}
    while (*bufferSTART < bufferEND && *bufferSTART < BUFFER_SIZE && (readded - *bufferSTART) && readded > 0)
    		line[index++] = buffada[(*bufferSTART)++];
	line[index++] = '\n';
    line[index] = '\0';
	free(*currentLINE);
    return (line);
}

char *get_next_line(int fd)
{
    static char	buffada[BUFFER_SIZE];
    static char *currentLINE = NULL;
	int 		ENDTOTAL = 0;
    static int 	bufferEND = 0;
	static int	bufferSTART = BUFFER_SIZE;
    static int 	readded = BUFFER_SIZE;

    if (fd < 0)
    	return (NULL);
    while (buffada[bufferEND] != '\n' && readded > 0 && readded == BUFFER_SIZE)
    {
        if (bufferSTART >= readded)
        {
            bufferEND = 0;
            readded = read(fd, buffada, BUFFER_SIZE);
        }
        while (buffada[bufferEND] != '\n' && bufferEND < readded)
		{
			bufferEND++;
			ENDTOTAL++;
		}
        currentLINE = nextline(&currentLINE, buffada, &bufferSTART, bufferEND, readded, ENDTOTAL);
    }
	if (buffada[bufferEND++] == '\n')
		bufferSTART++;
    return (currentLINE);
}


int main(void)
{
    int fd;

    fd = open("/home/olacerda/projetos/get_next_line/test.txt", O_RDONLY);
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
}
