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
	char	filename[100];
	int     fd;
	int     fd2;
  	size_t  i;

	line = NULL;
	i = 0;
	char  *files[] = {
		"test.txt",
		"./files/42_no_nl",
		"./files/41_with_nl",
		"./files/42_with_nl",
		"./files/41_no_nl",
		"./files/41_with_nl",
		"./files/42_no_nl",
		"./files/42_with_nl",
		"./files/43_no_nl",
		"./files/43_with_nl",
		"./files/alternate_line_nl_no_nl",
		"./files/alternate_line_nl_with_nl",
		"./files/big_line_no_nl",
		"./files/big_line_with_nl",
		"./files/empty",
		"./files/multiple_line_no_nl",
		"./files/multiple_line_with_nl",
		"./files/multiple_nlx5",
		"./files/nl",
		NULL
	};

	while (files[i])
	{
		sprintf(filename, "responses/file_%zu.txt", i);
		fd = open(files[i], O_RDONLY);
		fd2 = open(filename, O_WRONLY);
		printf("FILE: %s", files[i]);
		do
		{
			ft_clear(&line);
			line = get_next_line(fd);
			if (line != NULL)
			{
				printf("%s\n", line);
			}
		}
		while (line != NULL);
		close(fd);
		close(fd2);
		i++;
	}
	return (0);
}
