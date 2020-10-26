/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiholee <jiholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:58:54 by jiholee           #+#    #+#             */
/*   Updated: 2020/10/26 18:06:26 by jiholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	int		left_len;
	char	*tmp;

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
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			read_size;
	int			idx;
	char		buff[BUFFER_SIZE + 1];
	static char	*backup = 0;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
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
