/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:12:40 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/17 13:53:37 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_up_line(char *line, char *buffer)
{
	char	*new_line;
	int		i;
	int		j;

	new_line = malloc(sizeof(char) * (ft_strlen(line) + sizeline(buffer) + 2));
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	free(line);
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
	{
		new_line[i] = buffer[j];
		j++;
		i++;
	}
	if (buffer[j] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char	*get_line(char *buffer, int fd)
{
	int		ret;
	char	*line;

	ret = 1;
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	while (ret != 0 && no_newline(buffer))
	{
		if (buffer[0] != '\0')
		{
			line = ft_up_line(line, buffer);
			if (!line)
				return (bug_malloc(line));
		}
		ft_bzero(buffer, BUFFER_SIZE);
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
	}
	line = ft_up_line(line, buffer);
	if (!line)
		return (bug_malloc(line));
	return (line);
}

void	replace(char *buffer)
{
	char	tmp[BUFFER_SIZE + 1];
	int		i;
	int		j;

	i = 1;
	while (buffer[i - 1] != '\n' && buffer[i])
		i++;
	j = 0;
	while (i <= BUFFER_SIZE)
	{
		tmp[j] = buffer[i];
		j++;
		i++;
	}
	i = 0;
	while (i < j)
	{
		buffer[i] = tmp[i];
		i++;
	}
	while (i <= BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[2048][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) <= -1)
		return (NULL);
	line = get_line(buffer[fd], fd);
	if (!line)
		return (NULL);
	replace(buffer[fd]);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
