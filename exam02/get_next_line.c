#include "get_next_line.h"

int     ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return (len);
}
char    *ft_strdup(char *str)
{
    char *new;
    int len;
    int i = 0;

    len = ft_strlen(str);
    new = malloc(sizeof(char) * (len + 1));
    if (!new)
        return (NULL);
    while (str[i])
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}
char    *ft_strjoin(char *s1, char *s2)
{
    char *new;
    int len1;
    int len2;

    if (!s1)
        return (ft_strdup(s2));
    if (!s2)
        return (ft_strdup(s1));
    if (!s1 && !s2)
        return (NULL);
 
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);    
    new = malloc(sizeof(char) * (len1 + len2 + 1));
    if (!new)
        return (NULL);
    int i = 0, j = 0;
    while (s1[i])
    {
        new[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        new[i] = s2[j];
        i++;
        j++;
    }
    new[i] = '\0';
    return (new);
}

int		newline_check(char *backup)
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

int		line_split(char **backup, char **line, int idx)
{

	char	*tmp;

	(*backup)[idx] = '\0';
	*line = ft_strdup(*backup);
	tmp = ft_strdup(*backup + idx + 1);
	free(*backup);
	*backup = tmp;
	return (1);
}

int		backup_element_check(char **backup, char **line)
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
	return (0);
}

int		get_next_line(char **line)
{
	int			read_count;
	int			idx;
	char		buff[BUFFER_SIZE + 1];
	static char	*backup = 0;

	if (line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_count = read(0, buff, BUFFER_SIZE)) > 0)
	{
		buff[read_count] = '\0';
		backup = ft_strjoin(backup, buff);
		idx = newline_check(backup);
		if (idx >= 0)
		{
			return (line_split(&backup, line, idx));
		}
	}
	if (read_count < 0)
		return (-1);
	if (!backup)
		backup = ft_strdup("");
	return (backup_element_check(&backup, line));
}