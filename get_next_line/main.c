/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_nex_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	char	*buffer;

	fd = open("/Users/paula/Documents/get_next_line/texto.txt", O_RDONLY);
	if (fd == -1)
		printf("Error al abrir el archivo\n");
	else
	{
		//while (fd == 1)
		//{
			buffer = get_next_line(fd);
		//buffer = get_next_line(fd);
		printf("222%s\n", buffer);
		//}
	}
		fd = open("/Users/paula/Documents/get_next_line/texto.txt", O_RDONLY);
	if (fd == -1)
		printf("Error al abrir el archivo\n");
	else
	{
		//while (fd == 1)
		//{
			buffer = get_next_line(fd);
		//buffer = get_next_line(fd);
		printf("222%s\n", buffer);
		//}
	}
	return (0);
}

