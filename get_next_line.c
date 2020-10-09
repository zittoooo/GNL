#include "get_next_line.h"

int	get_newline(char *backup)  // backup[idx]에서 '\n' 찾음
{
	int	idx;

	idx = 0;
	while (backup[idx])
	{
		if (backup[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

int	line_split(char **backup, char **line, int idx)
{
	int		left_len;
	char	*temp;

	(*backup)[idx] = '\0';
	*line = ft_strdup(*backup);
	left_len = ft_strlen(*backup + idx + 1);
	if (left_len == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	temp = ft_strdup(*backup + idx + 1);
	free(*backup);
	*backup = temp;
	return (1);
}

int		last(char **backup, char **line, int rd_size)
{
	int	idx;

	if (rd_size < 0)  // read() 함수 읽기 실패  
		return (-1);
	if (*backup && (idx = get_newline(*backup)) >= 0) // *backup에 값이 있고 '\n'도 있음
	{
		return (line_split(backup, line, idx));
	}
	else if (*backup)
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}
/*
1 :  A line has been read
0 :  EOF has been reached
-1 :  An error happened

read, malloc, free

Write a function which returns a line read from a
file descriptor, without the newline.
*/
int		get_next_line(int fd, char **line) // 1.  file descriptor for reading  2.  The value of what has been read
{
	static char	*backup[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int			idx;
	int			rd_size; 

	idx = 0;
	if (fd < 0 || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((rd_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rd_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buff);
		if ((idx = get_newline(backup[fd]) >= 0))
			return (line_split(&backup[fd], line, idx));
	}
/*데이터를 다 읽어서 rd_size가 0일 때, backup에 남은 데이터 처리*/
	return (last(&backup[fd], line, rd_size));
}
