/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiholee <jiholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:42:08 by jiholee           #+#    #+#             */
/*   Updated: 2020/11/18 15:55:42 by jiholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		line_split(char **backup, char **line, char *p_line)
{
	char	*tmp;

	*p_line = '\0';
	*line = ft_strdup(*backup);
	tmp = ft_strdup(p_line + 1);
	free(*backup);
	*backup = tmp;
	return (1);
}

int		backup_element_check(char **backup, char **line)
{
	char *p_line;

	if (*backup)
	{
		p_line = ft_strchr(*backup, '\n');
		if (p_line != '\0')
			return (line_split(backup, line, p_line));
		else
		{
			*line = *backup;
			*backup = 0;
			return (0);
		}
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	char		*p_line;

	p_line = 0;
	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		p_line = ft_strchr(backup[fd], '\n');
		if (p_line != '\0')
			return (line_split(&backup[fd], line, p_line));
	}
	if (read_size < 0)
		return (-1);
	if (backup[fd] == 0)
		backup[fd] = ft_strdup("");
	return (backup_element_check(&backup[fd], line));
}
