/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:46:49 by otlacerd          #+#    #+#             */
/*   Updated: 2025/06/09 15:14:59 by olacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *nextline(char **currentLINE, char *buffada, int *bufferSTART, int *bufferEND, int ENDTOTAL)
{
    char *line;
    int index = 0;
    int count;

    count = 0;
    if (!buffada)
        return (NULL);
    line = malloc((*bufferEND + 2) * sizeof(char));
    if (!line)
        return (NULL);
    while (*bufferSTART && count < *bufferSTART)
        line[count] = (*currentLINE)[count], count++;
    while (*bufferSTART < *bufferEND)
        line[count + index++] = buffada[(*bufferSTART)++];
    line[index++] = '\n';
    line[index] = '\0';
    free(*currentLINE);
    return (line);
}

char *get_next_line(int fd)
{
    static char buffada[BUFFER_SIZE];
    static char *currentLINE = NULL;
    static int bufferSTART = 0;
    static int bufferEND = 0;
    static int ENDTOTAL = 0;
    static int readded = BUFFER_SIZE;

    if (fd < 0)
    return (NULL);
    while (buffada[bufferEND] != '\n' && readded == BUFFER_SIZE)
    {
        if (bufferEND >= readded)
        {
            bufferSTART = 0;
            bufferEND = 0;
            readded = read(fd, buffada, BUFFER_SIZE);
        }
        while (buffada[bufferEND] != '\n' && bufferEND < readded)
            bufferEND++;
        ENDTOTAL += bufferEND;
        currentLINE = nextline(&currentLINE, buffada, &bufferSTART, &bufferEND, ENDTOTAL);
    }
    bufferEND++;
    ENDTOTAL = 0;
    return (currentLINE);
}


int main(void)
{
    int fd;

    fd = open("/home/olacerda/projetos/get_next_line/test.txt", O_RDONLY);
    char *line1 = get_next_line(fd);
    printf("%s\n", line1);
    
    char *line2 = get_next_line(fd);
    printf("%s\n", line2);
    
    char *line3 = get_next_line(fd);
    printf("%s\n", line3);
}
