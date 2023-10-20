/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arubio-o <arubio-o@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:32:57 by arubio-o          #+#    #+#             */
/*   Updated: 2023/10/15 19:17:49 by arubio-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char    *line;
	char	out_filename[100];
    char	in_filename[100];
	int     fd;
	int     fd2;
    int     next;
  	size_t  i;

	line = NULL;
	i = 0;
	char  *files[] = {
            "1char.txt",
            "41_no_nl",
            "41_no_nl.txt",
            "41_with_nl",
            "42_no_nl",
            "42_with_nl",
            "43_no_nl",
            "43_with_nl",
            "alternate_line_nl_no_nl",
            "alternate_line_nl_with_nl",
            "big_line_no_nl",
            "big_line_with_nl",
            "el_quijote_ol.txt",
            "el_quijote.txt",
            "empty",
            "empty.txt",
            "giant_line_nl.txt",
            "giant_line.txt",
            "hola.txt",
            "lines_around_10.txt",
            "multiple_line_no_nl",
            "multiple_line_with_nl",
            "multiple_nl.txt",
            "multiple_nlx5",
            "nl",
            "one_line_no_nl.txt",
            "only_nl.txt",
            "read_error.txt",
            "test2.txt",
            "test_short_line.txt",
            "variable_nls.txt",
            NULL
	};

	while (files[i])
	{
        sprintf(in_filename, "files/%s", files[i]);
		fd = open(in_filename, O_RDONLY);
        sprintf(out_filename, "responses/%s", files[i]);
        fd2 = open(out_filename, O_WRONLY | O_TRUNC | O_CREAT, 0644);
        printf("%zu: %s\n", i,in_filename);
		do
		{
            next = line != NULL;
			ft_clear(&line);
			line = get_next_line(fd);
            if (next && line != NULL)
                write(fd2, "\n", 1);
			if (line != NULL)
                write(fd2, line, ft_strlen(line));
		}
		while (line != NULL);
		close(fd);
		close(fd2);
		i++;
	}
	return (0);
}
