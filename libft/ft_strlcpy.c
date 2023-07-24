/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:44:14 by schaisil          #+#    #+#             */
/*   Updated: 2022/06/13 07:39:07 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// note: copies up to dstsize - 1 characters from src to dst
//       guarantee NULL-termination if there is room
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	i;

	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}

// Guacamolle's libc behavior
// --------------------------
// [dst], [src], [size]
// s1, s2, 0 - do nothing -> return len_src
// NULL, s2, 0 - do nothing -> return len_src
// s1, NULL, 0 - segmentation fault
// NULL, NULL, 0 - segmentation fault
//
// s1, s2, 1 - copy 0 char, and put '\0' -> return len_src
// s1, s2, 2 - copy 1st char, and put '\0' -> return len_src
// s1, s2, dst_len+1 - copy dst_len char, and put '\0' -> return len_src
// s1, s2, dst_len+2 - illigal hardware instruction, overflow (skip)
// s1, s2, max: dst_len+1 (dst_len > src_len) - copy src_len char, and put '\0'
// s1, s2, max: dst_len+1 (src_len > dst_len) - copy dst_len char, and put '\0'
//
// s1, NULL, 1 - segmentation fault
// NULL, s2, 1 - segmentation fault
// NULL, NULL, 1 - segmentation fault
// --------------------------
