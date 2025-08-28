#include "get_next_line.h"

int main(void)
{
	char *buffada[100];
    int fd;
	static int	reads;

    fd = open("/home/olacerda/projetos/get_next_line/test.txt", O_RDONLY);
	reads = read(fd, buffada, 20);
	printf("%d\n", reads);
	// reads = read(fd, buffada, BUFFER_SIZE);
	// printf("%d\n", reads);
	// reads = read(fd, buffada, BUFFER_SIZE);
	// printf("%d\n", reads);
	// reads = read(fd, buffada, BUFFER_SIZE);
	// printf("%d\n", reads);
}
