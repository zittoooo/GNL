#ifndef NEXT_LINE_H
# define NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

#ifndef	OPEN_MAX
# define OPEN_MAX 32
#endif

#define EMPTY ""

int			get_next_line(int fd, char **line);
int			get_newline(char *backup);
int		    split_line(char **backup, char **line, int idx);
int         backup_iter(char **backup, char **line, int rd_size);

size_t		ft_strlen(const char *str);
char		*ft_strdup(char *str);
char		*ft_strjoin(char*s1, char *s2);
#endif

