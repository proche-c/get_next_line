/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_strjoin(char const *s1, const char *s2);

size_t	ft_strlen(const char *str);

char	*ft_get_next_line(char *buffer, char *read_lines)
{
	char	*next_line;
	int		i;
	size_t	length;

	if (read_lines)
		length = ft_strlen(read_lines);
	else
		length = 0;
	next_line = buffer;
	printf("length is %zd\n", length);
	//next_line = "holita";
	// = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	i = 0;
	while (buffer[length] != '\0' && buffer[length] != '\n')
	{
		next_line[i] = buffer[i];
		i++;
		length++;
	}
	next_line[i] = '\0';
	//free(next_line);
	return (next_line);
}

char	*ft_get_buffer(int fd)
{
	char		*buffer;
	ssize_t		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes == -1)
	{
		free (buffer);
		return (NULL);
	}
	buffer[read_bytes] = '\0';
	printf("read_bytes is %zd\n", read_bytes);
	free (buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*read_lines;
	char		*next_line;
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_get_buffer(fd);
	printf("After %s\n", buffer);
	next_line = ft_get_next_line(buffer, read_lines);
	printf("after get_next _line, next_line vale %s\n", next_line);
	if (read_lines)
		read_lines = ft_strjoin(read_lines, next_line);
	else
		read_lines = next_line;
	//free(next_line);
	return (next_line);
}
