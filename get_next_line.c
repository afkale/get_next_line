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

char *strljoin(char *dest, char *src, size_t n)
{
	size_t  i;
	char    *res;

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
	size_t          endl;
	char            *line;
	static t_buffer buffer;

	line = NULL;
  if (fd < 0 || BUFFER_SIZE <= 0)
    return (NULL);
	while (1)
	{
		if (buffer.last == 0)
		{
			buffer.count = read(fd, buffer.content, BUFFER_SIZE);
			if (buffer.count == 0)
      {
        ft_clear(&line);
        return (NULL);
      }
		}
		endl = strend(buffer);
		line = strljoin(line, buffer.content + buffer.last, endl);
		buffer.last += endl + 1;
		if (buffer.count != buffer.last - 1)
			return (line);
    buffer.last = 0;
	}
}
