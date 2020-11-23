#include <stdio.h>
#include "get_next_line_bonus.h"

int main()
{
	char *line;
	int ret;
	int fd;

	fd = open("/Users/jiholee/Desktop/project/get_next_line/GNL/file1", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	//printf("%s\nend\n\n", line);
	printf("%s", line);
	free(line);
	close(fd);


	fd = open("/Users/jiholee/Desktop/project/get_next_line/GNL/file2", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	if (ret < 0)
		return (0);
	printf("%s", line);
	free(line);
	close(fd);

	//while(1);

	return (0);

}
