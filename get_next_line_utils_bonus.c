/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiholee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:42:28 by jiholee           #+#    #+#             */
/*   Updated: 2020/11/18 12:42:29 by jiholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(char *str)
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

char		*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (0);
}
