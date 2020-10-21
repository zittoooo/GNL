#include <stdio.h>
#include "get_next_line.h"

int		newline_check(char *save)
{
	int i = 0;

	while (save[i])
	{
		if (save[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int 	line_split(char **save, int i, char **line)
{
	int left_len;
	char *tmp;

	(*save)[i] = '\0';
	*line = ft_strdup(*save);
	left_len = ft_strlen(*save + i + 1);
	if (left_len == 0)
	{
		free(*save);
		*save = 0;
		return (1);
	}
	tmp = ft_strdup(*save + i + 1);
	free(*save);
	*save = tmp;
	return (1);
}

int		save_check(char **save, char **line, int read_size)
{
	int				i;

	if (read_size < 0)
		return (-1);
	if (*save)
	{
		i = newline_check(*save);
		if (i >= 0)
			return (line_split(save, i, line));
		else
		{
			*line = *save;
			*save = 0;
			return (0);
		}
	}
	else
		*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char *save;
	char buff[BUFFER_SIZE + 1];
	int i;
	int read_size = 0;
	
	if (fd < 0 || line == 0)
		return (-1);
	while ((read_size = read(fd, buff, BUFFER_SIZE)) > 0)  // 실패시 -1	 파일끝에서 시도하면 0  반환값이 BUFFER_SIZE보다 작으면 파일의 끝을 만난것
	{
		buff[read_size] = '\0';
		save = ft_strjoin(save, buff);
		ft_memset(buff, 0, read_size);	
		i = newline_check(save);
		if (i >= 0)
		{
			return(line_split(&save, i, line));
		}
	}
	return (save_check(&save, line, read_size));
}  // return > 0 - 라인 있음  / return == 0  라인 없음.

int main(void)
{
	char *line = 0;
	int ret;
	int fd;
	fd = open("/Users/jiholee/Desktop/project/get_next_line/GNL/file1", O_RDONLY);

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s", line);
	free(line);
	close(fd);
}
