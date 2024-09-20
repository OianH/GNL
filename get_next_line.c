/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiahidal <oiahidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 01:14:31 by oiahidal          #+#    #+#             */
/*   Updated: 2024/09/20 13:41:05 by oiahidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	update_buffer(char *buff)
{
	int		i;
	int		j;

	j = search_for(buff, '\n');
	if (j == -1)
		return ;
	i = 0;
	j++;
	while (buff[i + j])
	{
		buff[i] = buff[i + j];
		i++;
	}
	buff[i] = '\0';
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin(NULL, buffer);
	read_bytes = 1;
	while (read_bytes > 0 && search_for(line, '\n') == -1)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		buffer[read_bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	if (line[0] == '\0')
		return (free(line), NULL);
	return (update_buffer(buffer), line);
}

/* #include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = open("test10.txt", O_RDONLY);
	if (fd < 0)
		return (printf("Error al abrir el archivo\n"), 1);
	char *line;
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return 0;
} */
