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

int	main(void)
{
	char    *line;
	int     fd;
  size_t  j;
  size_t  i;

  j = 0;
  char  *files[] = {
    "./test_short_line.txt",
    "./text.txt",
    "./hola.txt",
    "./el_quijote_ol.txt",
    "./el_quijote.txt",
  };

  for ( i = 0; i < sizeof(files); i++ ) {
    fd = open(files[i], O_RDONLY);
    do
    {
      ft_clear(&line);
      line = get_next_line(fd);
      printf("%d:\n%s\n",j++ ,line);
    } while (line != NULL);
    close(fd);
    j = 0;
  }
	return (0);
}
