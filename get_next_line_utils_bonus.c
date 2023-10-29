/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arubio-o <arubio-o@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:45:37 by arubio-o          #+#    #+#             */
/*   Updated: 2023/10/29 21:45:38 by arubio-o         ###   ########.fr       */
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

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
