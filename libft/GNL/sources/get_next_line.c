/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:44:38 by bozgur            #+#    #+#             */
/*   Updated: 2022/02/23 03:08:14 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	index;

	index = 0;
	if (!n || !src)
		return (dst);
	while (src[index] && index < n)
	{
		dst[index] = src[index];
		index++;
	}
	while (index <= n)
	{
		dst[index] = 0;
		index++;
	}
	return (dst);
}

static void	merge(char **buffer, char *rd_buf)
{
	char	*tmp;

	tmp = *buffer;
	*buffer = ft_strjoin(*buffer, rd_buf);
	free(tmp);
}

static char	*get_line(char **buffer)
{
	char	*line;
	char	*buf;
	int		len;

	if (!buffer || !*buffer)
		return (0);
	if (!**buffer)
	{
		free(*buffer);
		*buffer = 0;
		return (0);
	}
	buf = *buffer;
	len = 0;
	while (*buf && ++len && *buf++ != '\n')
		;
	line = (char *)malloc((len + 1) * sizeof(char));
	if (!line)
		return (0);
	ft_strncpy(line, *buffer, len);
	ft_strncpy(*buffer, *buffer + len, ft_strlen(*buffer));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*result;
	char		buffer[BUFFER_SIZE + 1];
	int			readbyte;

	*buffer = 0;
	while (!ft_strchr(result, '\n'))
	{
		readbyte = read(fd, buffer, BUFFER_SIZE);
		if (readbyte == -1)
			return (0);
		if (!readbyte)
			break ;
		buffer[readbyte] = 0;
		merge(&result, buffer);
	}
	return (get_line(&result));
}
