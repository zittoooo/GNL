/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiholee <jiholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:59:06 by jiholee           #+#    #+#             */
/*   Updated: 2020/11/16 14:26:32 by jiholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strjoin(char *str, char *buf)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (!str && !buf)
		return (NULL);
	else if (!str)
		return (ft_strdup(buf));
	else if (!buf)
		return (ft_strdup(str));
	new = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buf) + 1));
	if (!new)
		return (NULL);
	while (str[i])
		new[j++] = str[i++];
	free(str);
	i = 0;
	while (buf[i])
		new[j++] = buf[i++];
	new[j] = '\0';
	return (new);
}

char		*ft_strdup(char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!p)
		return (0);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
