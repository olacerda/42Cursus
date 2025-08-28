/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get42(1).c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:46:49 by otlacerd          #+#    #+#             */
/*   Updated: 2025/06/20 02:36:58 by olacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    liner(char **line, char *buffada, int *buff, int *ENDTOTAL)
{
    char        *newline;
    int         index;
	
    if (buff[READDED] <= 0)
    	return ;
    if (buff[START] >= buff[READDED])
		*(long *)buff = 0;
    while (buffada[buff[END]] != '\n' && buff[END] < buff[READDED]) // verifica se há linha & devolve index dela
    	buff[END]++, (*ENDTOTAL)++;
    newline = malloc(((*ENDTOTAL) + 1 + (buffada[buff[END]] == '\n')) * sizeof(char));
    if (!newline)
    	return ;
    index = -1;
    while (++index < ((*ENDTOTAL) - buff[END]) && *line) // copia linha anterior caso existir
    	newline[index] = (*line)[index];
    while (buff[START] <= buff[END] && buff[START] < buff[READDED]) // concatena noda linha identificada
    	newline[index++] = buffada[buff[START]++];
    newline[index] = '\0';
    free(*line);
    *line = newline;
}

char *get_next_line(int fd)
{
    static char buffada[BUFFER_SIZE];
    static int  buff[] = {BUFFER_SIZE, 0, BUFFER_SIZE};
    char        *line;
    int         ENDTOTAL;

    if (fd < 0 || BUFFER_SIZE <= 0)
    	return (NULL);
    if (buff[READDED] == 0)
    {
        buff[START] = BUFFER_SIZE;
        buff[END] = 0;
        buff[READDED] = BUFFER_SIZE;
    }
    line = NULL;
    ENDTOTAL = 0;
    while ((buffada[buff[END]] != '\n' && buff[READDED] > 0) \
		|| ((line == NULL || line[ENDTOTAL] != '\n') && buff[READDED] > 0))
    {
        if (buff[START] >= buff[READDED]) // verifica se read anterior foi 100% trabalhado & buffa outro
        		buff[READDED] = read(fd, buffada, BUFFER_SIZE);
		if (buff[READDED] == -1)
		{
			buff[START] = BUFFER_SIZE;
			buff[END] = 0;
			buff[READDED] = BUFFER_SIZE;
			return (free(line), NULL);
		}
        liner(&line, buffada, buff, &ENDTOTAL);
    }
    buff[END] += (buffada[buff[END]] == '\n');
    return (line);
}


int main(void)
{
    int fd;
    
    fd = open("./test.txt", O_RDONLY);

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