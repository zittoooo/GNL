#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
#endif

#include <unistd.h>
#include <stdlib.h>

int     get_next_line(char **line);
int     line_split(char **backup, char **line, int i);
int     backup_element_check(char **backup, char **line);
int     new_line(char *backup);

int     ft_strlen(char *str);
char    *ft_strdup(char *str);
char    *ft_strjoin(char *s1, char *s2);
#endif