/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:46:49 by otlacerd          #+#    #+#             */
/*   Updated: 2025/06/11 07:23:39 by olacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *nextline(char **currentLINE, char *buffada, int *bufferSTART, int bufferEND, int readded, int ENDTOTAL)
{
    char 		*line;
    int 		index;

	if (readded <= 0)
		return (NULL);
	index = 0;
	printf("endtotal: %d\n", ENDTOTAL);
	printf("condição pra zerar bufferSTART readded: %d - buffSTART: %d <= 0\n", readded, bufferEND);
	if ((readded - *bufferSTART) <= 0)
		*bufferSTART = 0;
    line = malloc((ENDTOTAL + 2) * sizeof(char));
    if (!line)
	{
        return (NULL);
	}
	printf("CONDICAO DE COPIA (readded: %d) 0 < (endotal:%d - bufferEND: %d\n", readded, ENDTOTAL, bufferEND);
    while (*bufferSTART && index < (ENDTOTAL - bufferEND))
	{
        line[index] = (*currentLINE)[index];
		index++;
		printf("copiando linha anterior!!!\n");
	}
	printf("CONDICAO DE NOVO BUFFER *bufferSTART:%d < bufferEND: %d\n", *bufferSTART, bufferEND);
    while (*bufferSTART < bufferEND && *bufferSTART < BUFFER_SIZE && (readded - bufferEND))
	{
        line[index++] = buffada[(*bufferSTART)++];
		printf("copiando novo buffer!!!\n");
	}
	line[index++] = '\n';
    line[index] = '\0';
	free(*currentLINE);
    return (line);
}

char *get_next_line(int fd)
{
    static char buffada[BUFFER_SIZE];
    static char *currentLINE = NULL;
	static int ENDTOTAL = 0;
    static int bufferEND = 0;
	static int	bufferSTART = 0;
    static int readded = 1;
	static int buffercount = 0;

    if (fd < 0)
    return (NULL);
    while (buffada[bufferEND] != '\n' && readded > 0)
    {
        if ((readded - bufferSTART) <= 0)
        {
            bufferEND = 0;
            readded = read(fd, buffada, BUFFER_SIZE);
			buffercount++;
			printf("BUFFOU: %d\n", buffercount);
        }
        while (buffada[bufferEND] != '\n' && bufferEND < readded && ((readded - bufferSTART) <= 0))
		{
            bufferEND++;
			ENDTOTAL++;
		}
		printf("WHILE DO bufferEND: %d\n", bufferEND);
        currentLINE = nextline(&currentLINE, buffada, &bufferSTART, bufferEND, readded, ENDTOTAL);
    }
	// if (buffada[bufferEND] == '\n')
	ENDTOTAL = 0;
	bufferEND++;
	//if (readded != BUFFER_SIZE && bufferEND >= readded)
	//	return(NULL);
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
}
