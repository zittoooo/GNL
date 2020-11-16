#include "get_next_line.h"
#include <stdio.h>

int		newline_check(char *backup)  //backup에 \n이 있으면 그 인덱스 리턴/ \n 없으면 -1리턴
{
	int idx;

	idx = 0;
	while (backup[idx])
	{
		if (backup[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

int		line_split(char **backup, char **line, int idx)  // 양수리턴 : 라인 한줄 읽었을 때
{
	char *tmp;
	int left_len;
	
	(*backup)[idx] = '\0';
	*line = ft_strdup(*backup);
	left_len = ft_strlen(*backup + idx + 1);
	if (left_len == 0)
	{
		*backup = 0;
		free(*backup);
		return (1);
	}
	tmp = ft_strdup(*backup + idx + 1);
	free(*backup);
	*backup = tmp;
	return (1);
}

int 	backup_element_check(char **backup, char **line)  // 양수리턴(0 제외) : 라인 한줄 읽었을 때
{
	int i;

	if (*backup)
	{
		i = newline_check(*backup);
		if (i >= 0)
			return (line_split(backup, line, i));
		else
		{
			*line = *backup;
			*backup = 0;
			return (0);
		}
	}
	//else (*backup == 0)
	*line = ft_strdup("");
	return (0);
}

int get_next_line(int fd, char **line)
{
	int 		read_size;
	int 		idx;
	char 		buff[BUFFER_SIZE + 1];
	static char *backup;

	idx = 0;
	while ((read_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[read_size] = '\0';
		backup = ft_strjoin(backup, buff);
		idx = newline_check(backup);
		if (idx >= 0)
		{
			return (line_split(&backup, line, idx));
		}

	}
	if (read_size < 0)
		return (-1);
	return (backup_element_check(&backup, line));
}

int main()
{
	char *line;
	int ret;
	int fd;

	fd = open("/Users/jiholee/Desktop/project/get_next_line/outline/file1", O_RDONLY);
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
	return (0);
}
