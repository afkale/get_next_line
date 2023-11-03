/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arubio-o <arubio-o@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:41:40 by arubio-o          #+#    #+#             */
/*   Updated: 2023/11/03 14:13:42 by arubio-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*strljoin(char *dest, char *src, size_t n)
{
	size_t	i;
	char	*res;

	i = 0;
	res = (char *) malloc(ft_strlen(dest) + n + 1);
	if (res != NULL)
	{
		if (dest != NULL)
		{
			while (dest[i])
			{
				res[i] = dest[i];
				i++;
			}
		}
		while (n--)
			res[i++] = *src++;
		res[i] = 0;
	}
	ft_clear(&dest);
	return (res);
}

char	*get_next_line(int fd)
{
	size_t			endl;
	char			*line;
	static t_buffer	buffer[OPEN_MAX];

	line = NULL;
	endl = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	while (1)
	{
		if (buffer[fd].last == 0)
			buffer[fd].count = read(fd, buffer[fd].content, BUFFER_SIZE);
		if (buffer[fd].count < 0)
			return (ft_clear(&line), NULL);
		if (buffer[fd].count == 0)
			return (line);
		endl = strend(&buffer[fd]);
		line = strljoin(line, buffer[fd].content + buffer[fd].last, endl);
		buffer[fd].last += endl;
		if (buffer[fd].last != buffer[fd].count)
			return (line);
		buffer[fd].last = 0;
		if (buffer[fd].content[buffer[fd].count - 1] == '\n')
			return (line);
	}
}
