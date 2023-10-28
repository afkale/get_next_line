/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale </var/spool/mail/ale>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:15:28 by ale               #+#    #+#             */
/*   Updated: 2023/10/28 16:30:50 by arubio-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_buffer {
	char	content[BUFFER_SIZE];
	int		last;
	int		count;
}		t_buffer;

void	ft_clear(char **str);
void	*ft_calloc(size_t size);
char	*get_next_line(int fd);
size_t	strend(t_buffer const *buffer);
size_t	ft_strlen(char *str);

#endif // !GET_NEXT_LINE_H
