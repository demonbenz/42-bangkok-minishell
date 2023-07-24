/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 08:02:05 by schaisil          #+#    #+#             */
/*   Updated: 2022/06/13 10:18:20 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// note: allocate enought space for count object that are size bytes
//       return pointer to allocated memory
//       allocated memory is filled with bytes of value zero
static int	is_total_memory_request_beyond_size_t_max_value(size_t count,
	size_t size)
{
	if (count == 0 || size == 0)
		return (0);
	if (size > (SIZE_MAX / count))
		return (1);
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;
	size_t	n;

	if (is_total_memory_request_beyond_size_t_max_value(count, size))
		return (NULL);
	ptr = malloc(count * size);
	if (ptr != NULL)
	{
		i = 0;
		n = count * size;
		while (i < n)
		{
			((unsigned char *) ptr)[i] = '\0';
			i++;
		}
	}
	return (ptr);
}

// libc behavior
// [count], [size]
// 0, any 					| malloc 0 byte
// SIZE_MAX, any (except 0) | cannot malloc, return null
// -1, -1					| cannot malloc, return null
// 1, -1 					| cannot malloc, return null
// 1, 1						| malloc 1 byte
