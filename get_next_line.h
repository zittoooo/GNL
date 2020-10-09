#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 500
#endif

#ifndef	OPEN_MAX
# define OPEN_MAX 32
#endif

#define EMPTY ""

int			get_next_line(int fd, char **line);
int			get_newline(char *backup);
int			line_split(char **backup, char **line, int idx);
int			last(char **backup, char **line, int rd_size);

size_t		ft_strlen(const char *str);
char		*ft_strdup(char *str);
char		*ft_strjoin(char*s1, char *s2);
#endif
