/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arubio-o <arubio-o@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:29:05 by arubio-o          #+#    #+#             */
/*   Updated: 2023/09/24 20:14:19 by arubio-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_calloc(size_t number, size_t size)
{
	size_t			i;
	unsigned char	res;

	i = 0;
	res = malloc(size * number);
	while (i < size)
		res[i] = 0;
	return (res);
}

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*dest_aux;
	unsigned char	*src_aux;

	dest_aux = (unsigned char *) dest;
	src_aux = (unsigned char *) src;

	if ((dest_aux + count) >= src)
		while (count--)
			*(dest_aux + count) = *(src_aux + count);
	else
		while (count--)
			*dest_aux++ = *src_aux++;
	return (dest);
}

void	*ft_realloc(const void *memblock, size_t size)
{
	unsigned char	*output;
	unsigned char	memblock;

	output = ft_calloc(size);



}

char	*get_next_line(int fd)
{



}


int	main()
{



}
