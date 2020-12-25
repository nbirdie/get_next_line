/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdie <nbirdie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:56:25 by nbirdie           #+#    #+#             */
/*   Updated: 2020/12/25 19:57:22 by nbirdie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_GET_NEXT_LINE_H
# define GET_NEXT_LINE_GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
int		ft_strchr(char *s, int c);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_memcpy(char *dst, char *src, int n);
char	*ft_get_line(char *cache, char **line, int index);
char	*ft_get_line_end(char **line, char *cache);
int		get_next_line(int fd, char **line);

#endif
