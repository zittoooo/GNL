/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiholee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:42:52 by jiholee           #+#    #+#             */
/*   Updated: 2020/11/18 12:42:53 by jiholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 32
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int			get_next_line(int fd, char **line);
int			line_split(char **backup, char **line, char *p_line);
int			backup_element_check(char **backup, char **line);

size_t		ft_strlen(char *str);
char		*ft_strdup(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(char *s, char c);
#endif
