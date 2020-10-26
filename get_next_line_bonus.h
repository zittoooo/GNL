/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiholee <jiholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:59:37 by jiholee           #+#    #+#             */
/*   Updated: 2020/10/26 18:07:04 by jiholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

# ifndef OPEN_MAX
#  define OPEN_MAX 32
# endif

size_t		ft_strlen(char *str);
char		*ft_strdup(char *str);
char		*ft_strjoin(char *s1, char *s2);

int			newline_check(char *backup);
int			line_split(char **backup, char **line, int idx);
int			backup_element_check(char **backup, char **line);
int			get_next_line(int fd, char **line);
#endif
