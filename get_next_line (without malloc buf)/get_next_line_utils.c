/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdie <nbirdie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:05:55 by nbirdie           #+#    #+#             */
/*   Updated: 2020/12/24 03:33:09 by nbirdie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strchr(char *s, int c)
{
	char	*ss;
	char	a;
	int		i;

	a = (char)c;
	ss = (char *)s;
	i = 0;
	if (!ss)
		return (-1);
	while (*ss)
	{
		if (*ss++ == a)
			return (i);
		i++;
	}
	return (-1);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*nsrc;

	i = 0;
	if (!src)
		return (NULL);
	i = ft_strlen(src);
	if (!(nsrc = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	j = 0;
	while (i--)
	{
		nsrc[j] = src[j];
		j++;
	}
	nsrc[j] = '\0';
	return (nsrc);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i1;
	size_t	i2;
	size_t	i;
	size_t	j;

	i1 = 0;
	i2 = 0;
	i = -1;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1 != '\0')
		i1 = ft_strlen(s1);
	if (s2 != '\0')
		i2 = ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * (i1 + i2 + 1))))
		return (NULL);
	while (++i < i1)
		res[i] = s1[i];
	while (i2--)
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}
