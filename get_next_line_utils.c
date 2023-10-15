/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arubio-o <arubio-o@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:32:57 by arubio-o          #+#    #+#             */
/*   Updated: 2023/10/15 18:24:37 by arubio-o         ###   ########.fr       */
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

size_t	strend(t_buffer buffer)
{
	size_t	i;
	size_t  last;
	char    *aux;
		
	last = buffer.count - buffer.last;
	aux = buffer.content + buffer.last;
	i = 0;
	if (aux == NULL)
		return (i);
	while (aux[i] != '\n' && i < last)
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

void	*ft_calloc(size_t size)
{
	unsigned char	*res;

	res = malloc(size);
	if (res == NULL)
		return (NULL);
	while (size--)
		res[size] = 0;
	return (res);
}
