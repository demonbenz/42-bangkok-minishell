/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:21:18 by schaisil          #+#    #+#             */
/*   Updated: 2022/06/13 09:51:12 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// note: copy n bytes from src to dst,
//       if dst and src overlap, behavior is undefine
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL && n > 0)
		return (dst);
	i = 0;
	while (i < n)
	{
		((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dst);
}

// Guacamolle's clib behavior
// --------------------------
// [dst], [src], [size]
// s1, s2, 0 - do nothing
// NULL, s2, 0 - do nothing
// s1, NULL, 0 - do nothing
// NULL, NULL, 0 - do nothing
//
// s1, s2, 1 - normal copy
// s1, NULL, 1 - segmentation fault
// NULL, s2, 1 - segmentation fault
// NULL, NULL, 1 - do nothing
// --------------------------
