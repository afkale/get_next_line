/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arubio-o <arubio-o@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:04:17 by arubio-o          #+#    #+#             */
/*   Updated: 2023/10/15 18:57:18 by arubio-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static t_buffer	buffer;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer.last == 0)
		{
			buffer.count = read(fd, buffer.content, BUFFER_SIZE);
			if (buffer.count <= 0)
				return (line);
		}
		endl = strend(buffer);
		line = strljoin(line, buffer.content + buffer.last, endl);
		buffer.last += endl + 1;
		if (buffer.count != buffer.last - 1)
			return (line);
		buffer.last = 0;
	}
}
//
//int main(int argc, char *argv[])
//{
//	int     fd;
//	char    *line;
//
//	if (argc != 2)
//		return (1);
//	line = NULL;
//	fd = open(argv[1], O_RDONLY);
//	do
//	{
//		ft_clear(&line);
//		line = get_next_line(fd);
//		if (line != NULL)
//		{
//			printf("%s\n", line);
//		}
//	}
//	while (line != NULL);
//}
