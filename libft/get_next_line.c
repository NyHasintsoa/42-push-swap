/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 08:11:16 by nramalan          #+#    #+#             */
/*   Updated: 2026/02/27 21:13:38 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_fd(int fd, char *buffer)
{
	char	*buf_read;
	int		bytes_read;

	buf_read = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf_read)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buf_read, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buf_read);
			return (NULL);
		}
		buf_read[bytes_read] = '\0';
		buffer = ft_strjoin_line(buffer, buf_read);
	}
	free(buf_read);
	return (buffer);
}

static char	*ft_get_line(char const *buffer)
{
	size_t	i;
	size_t	length;
	char	*str;

	length = 0;
	while (buffer[length] && buffer[length] != '\n')
		length++;
	if (buffer[length] == '\n')
		str = (char *) malloc(sizeof(char) * (length + 2));
	else
		str = (char *) malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < length)
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[length] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

static char	*ft_create_next_buffer(char *buffer, size_t start)
{
	char	*next;
	size_t	i;

	next = (char *) malloc(sizeof(char) * (ft_strlen(buffer + start) + 1));
	if (!next)
		return (NULL);
	i = 0;
	while (buffer[start + i])
	{
		next[i] = buffer[start + i];
		i++;
	}
	next[i] = '\0';
	return (next);
}

static char	*ft_get_leftover(char *buffer)
{
	size_t	i;
	char	*next;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next = ft_create_next_buffer(buffer, i + 1);
	free(buffer);
	if (next && *next == '\0')
	{
		free(next);
		return (NULL);
	}
	return (next);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_fd(fd, buffer);
	if (!buffer)
		return (NULL);
	if (buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_get_line(buffer);
	buffer = ft_get_leftover(buffer);
	return (line);
}
