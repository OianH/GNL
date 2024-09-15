/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiahidal <oiahidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 01:14:31 by oiahidal          #+#    #+#             */
/*   Updated: 2024/07/04 01:14:31 by oiahidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1) + 1;
	ptr = malloc(ft_strlen(s1) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	if (ft_strlen(ptr) > len)
		return (NULL);
	return (ptr);
}

char	*extract_line(char *rest)
{
	char	*line;
	int		i;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
	{
		line[i] = rest[i];
		i++;
	}
	line[i] = '\0';
	printf("patata\n");
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	ssize_t		read_bytes;
	char		buffer[BUFFER_SIZE + 1];

	if (!rest)
		rest = ft_strdup("");
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_bytes = 0;
	while (read_bytes >= 0 && !gnl_strchr(rest, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		rest = ft_strjoin(rest, buffer);
		if (gnl_strchr(buffer, '\n'))
			break ;
	}
	if (read_bytes <= 0)
		return (NULL);
	line = extract_line(rest);
	if (line == NULL || *line == '\0')
		return (free(line), NULL);
	printf("platano\n");
	return (line);
}

#include <fcntl.h>
#include <stdio.h>
int main(void)
{
	int i = 0;
	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (printf("Error al abrir el archivo\n"), 1);
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
		printf("WHILE %d\n", i);
		i++;
	}
	close(fd);
	return 0;
}
