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

void	ft_read(void)
{
	int	fd;

	fd = open("./test_short_line.txt", O_RDONLY);
	g_buffer.size = read(fd, buffer.content, BUFFER_SIZE - 1);
}

int	main(void)
{
	printf("%s, %zu, %zu\n", g_buffer.content, g_buffer.size, g_buffer.last);
}

/*
 * 
 *
 */
