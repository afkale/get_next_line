/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale </var/spool/mail/ale>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:15:39 by ale               #+#    #+#             */
/*   Updated: 2023/10/29 15:31:56 by arubio-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_clear(char **str)
{
	if (*str == NULL)
		return ;
	free(*str);
	*str = NULL;
}

size_t	strend(t_buffer const *buffer)
{
	size_t		i;
	size_t		last;
	const char	*aux;

	last = buffer->count - buffer->last;
	aux = buffer->content + buffer->last;
	i = 0;
	if (aux == NULL)
		return (i);
	while (i < last && aux[i] != '\n')
		i++;
	if (i < last && aux[i] == '\n')
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
