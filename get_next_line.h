/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arubio-o <arubio-o@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:45:53 by arubio-o          #+#    #+#             */
/*   Updated: 2023/10/29 21:45:55 by arubio-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_buffer {
	char	content[BUFFER_SIZE];
	int		last;
	int		count;
}		t_buffer;

void	ft_clear(char **str);
char	*get_next_line(int fd);
size_t	strend(t_buffer const *buffer);
size_t	ft_strlen(char *str);

#endif // !GET_NEXT_LINE_H
