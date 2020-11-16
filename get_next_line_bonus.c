/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiholee <jiholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:59:22 by jiholee           #+#    #+#             */
/*   Updated: 2020/11/16 14:43:46 by jiholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

int		get_next_line(int fd, char **line)
{
	int			read_count;
	int			idx;
	char		buff[BUFFER_SIZE + 1];
	static char	*backup[OPEN_MAX];

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_count = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[read_count] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buff);
		idx = newline_check(backup[fd]);
		if (idx >= 0)
		{
			return (line_split(&backup[fd], line, idx));
		}
	}
	if (read_count < 0)
		return (-1);
	if (backup[fd] == '\0')
		backup[fd] = ft_strdup("");
	return (backup_element_check(&backup[fd], line));
}
