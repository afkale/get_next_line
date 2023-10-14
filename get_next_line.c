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
	if (res != NULL)
  {
    if (dest != NULL)
      while (dest[i])
      {
        res[i] = dest[i];
        i++;
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
			size = read(fd, buffer.content, BUFFER_SIZE);
			if (size > 0)
				buffer.content[size] = 0;
      else
        return (NULL);
		}
		endl = strend(buffer.content + buffer.last);
		line = strljoin(line, buffer.content + buffer.last, endl);
		if (ft_strlen(buffer.content) != buffer.last + endl)
		{
			buffer.last += endl + 1;
			return (line);
		}
		else
			buffer.last = 0;
	}
	return (line);
}

int	main(void)
{
	char    *line;
	int     fd;
  size_t  i;

  i = 0;
	fd = open("./test_short_line.txt", O_RDONLY);
  do
  {
	  line = get_next_line(fd);
    printf("LINE %d: len %zu\n%s\n", i++, ft_strlen(line), line);
    ft_clear(&line);
  } while (i < 4);
	return (0);
}
