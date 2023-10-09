/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arubio-o <arubio-o@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:32:57 by arubio-o          #+#    #+#             */
/*   Updated: 2023/10/07 15:36:15 by arubio-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


int	has_endl(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		if (str[i] == '\0')
			return (1);
	return (0);
}

void	get_next_line(int fd)
{
	int		size;
	char		*line;
	static s_buffer *buffer;

	size = 0;
	if (buffer->last == 0)	
	{
		size = read(fd, buffer->content, BUFFER_SIZE -1);
		if (size > 0)
			buffer->content[size] = 0;
		while (size > 0 && !has_endl(buffer->content))
		{
			line = line + buffer->content;
		}
	}
}

/*
 *	fd = open("./test_short_line.txt", O_RDONLY);
 *	g_buffer.size = read(fd, g_buffer.content, BUFFER_SIZE - 1);
 *	g_buffer.content[g_buffer.size] = 0;
 *	printf("%s\n", g_buffer.content);
 *	g_buffer.size = read(fd, g_buffer.content, BUFFER_SIZE - 1);
 *	g_buffer.content[g_buffer.size] = 0;
 *	printf("%s\n", g_buffer.content);
 *	close(fd);
 */

int	main(void)
{
	fd = open("./test_short_line.txt", O_RDONLY);
	get_next_line(fd)
}
