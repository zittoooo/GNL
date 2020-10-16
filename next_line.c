#include "next_line.h"

int     get_newline(char *s)
{
    int idx;

    idx = 0;
    while (s[idx])
    {
        if (s[idx]== '\n')
            return (idx);
        idx++;
    }
    return (-1);
}

int    backup_iter(char **backup, char **line, int rd_size)
{
    int idx = 0;

    if (rd_size < 0)
        return (-1);
            
    if (*backup && (idx = get_newline(*backup)) >= 0)
    {
        return (split_line(backup, line, idx));
    }
    else if (*backup)
    {
        *line = *backup;
        *backup = 0;
        free(*backup);
        return (0);
    }
    *line = ft_strdup("");  // 아무것도 없는 빈 파일이 들어왔을 때
    return (0);
}

int    split_line(char **backup, char **line, int idx)
{
    int left_len;
    char *tmp;

    (*backup)[idx] = '\0';
    *line = ft_strdup(*backup);

    left_len = ft_strlen(*backup + idx + 1);
    if (left_len == 0)
    {
        free(*backup);
        *backup = 0;
        return (1);
    }
    tmp = ft_strdup(*backup + idx + 1);
    free(*backup);
    *backup = tmp;
    return (1);
}

/*returns a line read from a
file descriptor, without the newline.*/
int     get_next_line(int fd, char **line)
{
    int     rd_size;
    char    buff[BUFFER_SIZE + 1];
    static char *backup;
    int idx;

    if (fd < 0 || (line == 0) || BUFFER_SIZE <= 0)
        return (-1);
    while ((rd_size = read(fd, buff, BUFFER_SIZE)) > 0)   // 0 : 읽은게 없다 / 음수 : 
    {
        buff[rd_size] = '\0';
        backup = ft_strjoin(backup, buff);
        idx = get_newline(backup);
        if (idx >= 0)
            return (split_line(&backup, line, idx));    
    }
    return (backup_iter(&backup, line, rd_size));
   
}

int	main()
 {
 	int		ret;
 	int		fd;
 	char	*line;

	fd = open("MY_TEXT.txt", O_RDONLY);
	while ((ret = (get_next_line(fd, &line)) > 0))  // a line has been read
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s", line);
	free(line);
    close(fd);
}
