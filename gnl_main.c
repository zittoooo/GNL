#include <stdio.h>
#include "get_next_line.h"

int main()
{
	char *line;
	int ret;
	int fd;

	fd = open("/Users/jiholee/Desktop/project/get_next_line/GNL/file2", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s", line);
	free(line);
    while(1);

	close(fd);
    return (0);
}