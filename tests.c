/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale </var/spool/mail/ale>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:53:51 by ale               #+#    #+#             */
/*   Updated: 2023/10/28 10:58:55 by ale              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

int	test1(void)
{
	char		*line;
	char		out_filename[100];
	char		in_filename[100];
	int			fd;
	int			fd2;
	int			next;
	size_t		i;
	const char	*files[] = {
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
		"test_nl",
		"test_short_line.txt",
		"variable_nls.txt",
		NULL
	};

	line = NULL;
	i = 0;
	while (files[i])
	{
		sprintf(in_filename, "files/%s", files[i]);
		fd = open(in_filename, O_RDONLY);
		sprintf(out_filename, "responses/%s", files[i]);
		fd2 = open(out_filename, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		printf("%zu: %s\n", i + 1, in_filename);
		while ((line = get_next_line(fd)))
		{
			write(fd2, line, ft_strlen(line));
			ft_clear(&line);
		}
		close(fd);
		close(fd2);
		i++;
	}
	return (0);
}

int	test2(int argc, char *argv[])
{
	int		fd;
	char	*line;
	int		line_number;

	line_number = 0;
	line = NULL;
	if (argc != 2)
	{
		printf("Te faltan los parametros");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%d: %s", line_number++, line);
		ft_clear(&line);
	}
	printf("%d: %s", line_number++, line);
	close(fd);
	printf("\n");
	return (0);
}

int	test3(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = -1;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		ft_clear(&line);
	}
	fd = 100;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		ft_clear(&line);
	}
}

int	main(int argc, char *argv[])
{
	test1();
	return (0);
}
