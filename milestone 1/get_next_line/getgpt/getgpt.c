#include "getgpt.h"

static char	*extract_line(char *storage)
{
	int		i;
	char	*line;

	if (!storage || !storage[0])
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*clean_storage(char *storage)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	rest = malloc(ft_strlen(storage + i) + 1);
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (storage[i])
		rest[j++] = storage[i++];
	rest[j] = '\0';
	free(storage);
	return (rest);
}

static char	*read_and_append(int fd, char *storage)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(storage, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			free(storage);
			return (NULL);
		}
		buffer[bytes] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_and_append(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	storage = clean_storage(storage);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	// int fd = open("test.txt", O_RDONLY);
	// char *line;

	// if (fd < 0)
	// 	return (1);
	// while ((line = get_next_line(fd)))
	// {
	// 	printf("line: %s", line);
	// 	free(line);
	// }
	// printf("\n\nRound 2\n\n");
	// close(fd);
	// fd = open("test.txt", O_RDONLY);
	// if (fd < 0)
	// 	return (1);
	// while ((line = get_next_line(fd)))
	// {
	// 	printf("line: %s", line);
	// 	free(line);
	// }
	// printf("\n");
	// close(fd);
	// return (0);
	int fd;

    fd = open("./test.txt", O_RDONLY);
	printf("open %i\n", fd);
    char *line1 = get_next_line(fd);
    printf("GET1:  %s", line1);
    
    // char *line2 = get_next_line(fd);
    // printf("GET2:  %s", line2);
    
    // char *line3 = get_next_line(fd);
    // printf("GET3:  %s", line3);
	
    // char *line4 = get_next_line(fd);
    // printf("GET4:  %s", line4);
	
    // char *line5 = get_next_line(fd);
    // printf("GET5:  %s\n", line5);

	printf("\n\nAfter close:\n\n\n");
	
	close(fd);
    fd = open("./test.txt", O_RDONLY);
	printf("open %i\n", fd);
    line1 = get_next_line(fd);
    printf("GET1:  %s", line1);
    
    char *line2 = get_next_line(fd);
    printf("GET2:  %s", line2);
    
    char *line3 = get_next_line(fd);
    printf("GET3:  %s", line3);
	
    char *line4 = get_next_line(fd);
    printf("GET4:  %s", line4);
	
    char *line5 = get_next_line(fd);
    printf("GET5:  %s\n", line5);
}