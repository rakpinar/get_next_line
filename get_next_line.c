/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakpinar <rakpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:15:01 by rakpinar          #+#    #+#             */
/*   Updated: 2023/02/20 18:45:15 by rakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*line;
	int		new_line;

	i = 0;
	new_line = ft_strchr(buffer, '\n');
	if (!buffer[i])
		return (0);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 1 + new_line);
	if (!line)
		return (0);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_get_new_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = ft_strlen(buffer);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (0);
	}
	new_line = malloc(sizeof(char) * (j - i) + 1);
	if (!new_line)
		return (0);
	j = 0;
	i++;
	while (buffer[i] != '\0')
		new_line[j++] = buffer[i++];
	new_line[j] = '\0';
	free(buffer);
	return (new_line);
}

char	*ft_get_read(int fd, char *buffer)
{
	int		rd_byte;
	char	*now_buffer;

	now_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!now_buffer)
		return (0);
	rd_byte = 1;
	while (!ft_strchr(buffer, '\n') && rd_byte != 0)
	{
		rd_byte = read(fd, now_buffer, BUFFER_SIZE);
		if (rd_byte == -1)
		{
			free(now_buffer);
			return (0);
		}
		now_buffer[rd_byte] = '\0';
		buffer = ft_strjoin(buffer, now_buffer);
	}
	free(now_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
	{
		return (0);
	}
	buffer = ft_get_read(fd, buffer);
	if (!buffer)
		return (0);
	line = ft_get_line(buffer);
	buffer = ft_get_new_buffer(buffer);
	return (line);
}
