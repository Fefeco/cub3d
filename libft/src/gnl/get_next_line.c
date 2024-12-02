/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:04:50 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/02 14:03:10 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (*str++)
		++len;
	return (len);
}

static char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	size_t	total_len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!joined)
		return (NULL);
	i = -1;
	while (s1[++i])
		joined[i] = s1[i];
	j = 0;
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = '\0';
	return (joined);
}

static void	ft_move_buf_content(char *src_buf, char *dst_buf)
{
	int	pos;

	pos = -1;
	while (src_buf[++pos])
	{
		dst_buf[pos] = src_buf[pos];
		src_buf[pos] = '\0';
	}
	while (pos <= BUFFER_SIZE)
		dst_buf[pos++] = '\0';
}

static int	ft_read_file(char **line, int fd)
{
	char	*read_buf;
	char	*joined_buf;
	int		bytes_read;
	int		pos;

	read_buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_buf)
	{
		free (*line);
		return (-1);
	}
	pos = 0;
	while (pos <= BUFFER_SIZE)
		read_buf[pos++] = '\0';
	bytes_read = read(fd, read_buf, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		joined_buf = ft_strjoin(*line, read_buf);
		free (*line);
		*line = joined_buf;
	}
	free (read_buf);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	static_buf[MAX_FD][BUFFER_SIZE];
	char		*line;
	char		*newl_ptr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	ft_move_buf_content(static_buf[fd], line);
	newl_ptr = ft_get_newl_ptr(line);
	while (!newl_ptr && ft_read_file(&line, fd) > 0)
		newl_ptr = ft_get_newl_ptr(line);
	if (newl_ptr)
		ft_move_buf_content(newl_ptr + 1, static_buf[fd]);
	if (line && !*line)
	{
		free (line);
		line = NULL;
	}
	return (line);
}
