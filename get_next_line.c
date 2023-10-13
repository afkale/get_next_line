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

int	has_endl(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (1);
	return (0);
}

void	ft_clear(char **str)
{
	if (*str == NULL)
		return ;
	free(*str);
	*str = NULL;
}

size_t	strend(char	*str)
{

	size_t	i;
	
	i = 0;
	if (str == NULL)
		return (i);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);

}

size_t	ft_strlen(char *str)
{
	size_t	i;
	
	i = 0;
	if (str == NULL)
		return (i);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t size)
{
	unsigned char	*res;

	res = malloc(size);
	if (res == NULL)
		return (NULL);
	while (size--)
		res[size] = 0;
	return (res);

}

char	*strljoin(char *dest, char *src, size_t n)
{
	size_t	i;
	char	*res;

	i = 0;
	res = (char *) malloc(ft_strlen(dest) + n + 1);
	if (res == NULL)
		return (dest);
	if (dest != NULL)
		while (dest[i])
		{
			res[i] = dest[i];
			i++;
		}
	ft_clear(&dest);
	while (n--)
		res[i++] = *src++;
	res[i] = 0;
	return (res);
}

char	*get_next_line(int fd)
{
	size_t			size;
	size_t			endl;
	char			*line;
	static t_buffer buffer;

	line = NULL;
	size = 1;
	endl = 1;
	while (size > 0)
	{
		if (buffer.last == 0)
		{
			size = read(fd, buffer.content, BUFFER_SIZE -1);
			if (size > 0)
				buffer.content[size] = 0;
		}
		endl = strend(buffer.content + buffer.last);
		line = strljoin(line, buffer.content + buffer.last, endl);
		if (endl != size)
		{
			buffer.last = endl + 1;
			return (line);
		}
		else
			buffer.last = 0;
	
	}
	return (line);
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
	char	*line;
	int		fd;

	fd = open("./test_short_line.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("LINE 1: len %zu\n", ft_strlen(line));
	printf("%s\n", line);
	free(line);

	line = get_next_line(fd);
	printf("LINE 2: len %zu\n", ft_strlen(line));
	printf("%s\n", line);
	free(line);

	line = get_next_line(fd);
	printf("LINE 3: len %zu\n", ft_strlen(line));
	printf("%s\n", line);
	free(line);

	line = get_next_line(fd);
	printf("LINE 4: len %zu\n", ft_strlen(line));
	printf("%s\n", line);
	free(line);

	return (0);
}
