/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdie <nbirdie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:05:18 by nbirdie           #+#    #+#             */
/*   Updated: 2020/12/25 20:09:06 by nbirdie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_get_line(char *cache, char **line, int index)
{
	char		*tmp;

	cache[index] = '\0';
	*line = ft_strdup(cache);
	if (ft_strlen(cache + index + 1) == 0)
	{
		free(cache);
		cache = ft_strdup("");
		return (cache);
	}
	tmp = ft_strdup(cache + index + 1);
	free(cache);
	cache = tmp;
	return (cache);
}

char			*ft_get_line_end(char **line, char *cache)
{
	*line = ft_strdup(cache);
	free(cache);
	cache = 0;
	return (cache);
}

int				ft_return(char *cache, int index)
{
	if (cache && index >= 0)
		return (1);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char		linee[BUFFER_SIZE + 1];
	int			rs;
	int			index;
	static char	*cache;
	int			retnum;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	cache = (!cache) ? (ft_strdup("")) : (cache);
	while ((index = ft_strchr(cache, 10)) == -1 &&
	(rs = read(fd, linee, BUFFER_SIZE)) > 0)
	{
		linee[rs] = '\0';
		cache = ft_strjoin(cache, linee);
	}
	if (rs < 0)
		return (-1);
	retnum = ft_return(cache, index);
	if (cache && (index = ft_strchr(cache, 10)) >= 0)
		cache = ft_get_line(cache, line, index);
	else if (cache)
		cache = ft_get_line_end(line, cache);
	else
		*line = ft_strdup("");
	return (retnum);
}
